local USER_CREATED_MENU_JSON_PATH = "data/menu.json"
local MENUS_PATH = "sections/menus.inc"
local JSON_SCRIPT_PATH = "scripts/json.lua"

local COMMENTS = "; DO NOT MANUALLY EDIT\n"
	.. "; ALL EDITS WILL BE LOST ONCE IT DETECTS A NEW BUTTON\n"
	.. "; MenuMaster.lua handles the editing of this file\n" 

local ADD_CUSTOM_VARIABLES = "\n[AddCustomVariables]\n"
	.. "@includeVariables=\"../data/variables.inc\"\n"

local MENU_MASTER_MEASURE = "\n[MenuMaster]\n"
	.. "Measure=Script\n"
	.. "ScriptFile=scripts/MenuMaster.lua\n"
	.. "Disabled=1\n"
			
local GENERIC_MENU_BUTTON_STYLE = "\n[GenericMenuButtonStyle]\n"
	.. "FontColor=200,200,200,255\n"
	.. "FontSize= 11\n"
	.. "FontWeight=400\n"
	.. "FontFace=Roboto\n"
	.. "AntiAlias=1\n"
	.. "StringAlign=LeftCenter\n"		
	.. "ClipString=1\n"

local GENERIC_SUBMENU_BUTTON_STYLE = "\n[GenericSubmenuButtonStyle]\n"
	.. "SolidColor=#BackgroundColor#\n"
	.. "Padding=10,3,0,3\n"
	.. "DynamicVariables=1\n"
	.. "W=250\n"
	.. "H=25\n"
	.. "Hidden=1\n"

-- Invisibile meter that moves the margin of the menu to the right
local PADDING_LEFT = "\n[PaddingLeft]\n"
	.."Meter=String\n"
	.."X=#PaddingLeft#\n"
	.."Y=(#PaddingTop#+4)\n"
	.."W=25\n"
	.."H=25\n" 

local RAINMETER_METER = "\n[Rainmeter]\n" 
	.. "LeftMouseUpAction=[!CommandMeasure MenuMaster \"RainmeterOnClick()\"]\n"

local groups = {}
		
function Initialize ()
	
	-- get json script
	local json = assert(loadfile(SKIN:MakePathAbsolute(JSON_SCRIPT_PATH)))() 

	-- get and decode the menu.json
	local data = ReadFile(USER_CREATED_MENU_JSON_PATH)
	data = json.decode(data)
	if not data then return end	

	-- Initialize Groups
	for key, value in pairs(data) do
		table.insert(groups, value["name"])
	end

	-- Combine the strings
	menusInc = COMMENTS
	.. RAINMETER_METER
	.. ADD_CUSTOM_VARIABLES
	.. MENU_MASTER_MEASURE
	.. GENERIC_MENU_BUTTON_STYLE
	.. GENERIC_SUBMENU_BUTTON_STYLE
	.. PADDING_LEFT
	.. CreateMenu(data)
	
	-- Write to menus.inc file
	-- OPEN FILE.
	local file = io.open(SKIN:MakePathAbsolute(MENUS_PATH), "w+")

	-- HANDLE ERROR OPENING FILE.
	if not file then
		print('ReadFile: unable to open menus path at ' .. MENUS_PATH)
		return
	end

	io.output(file)
	io.write(menusInc)
	io.close(file)
end

local previousOpenedSubmenu = "None"
local OpenedSubmenu = "None"

CurrentX = 0

function TopMenuOnClick (meterName)
	local meter = SKIN:GetMeter(meterName)
	CurrentX = meter:GetX()

	-- close all submenus
	for key,value in ipairs(groups) do
		SKIN:Bang("!HideMeterGroup", value)
	end

	previousOpenedSubmenu = OpenedSubmenu
	OpenedSubmenu = meterName

	if(previousOpenedSubmenu == OpenedSubmenu) then

		previousOpenedSubmenu = OpenedSubmenu
		OpenedSubmenu = "None"
	else 
		SKIN:Bang("!ShowMeterGroup", OpenedSubmenu)
	end
end

function TopMenuOnMouseOver (meterName) 

	if(OpenedSubmenu == "None") then return end

	-- close all submenus
	for key,value in ipairs(groups) do
		SKIN:Bang("!HideMeterGroup", value)
	end	
	
	local meter = SKIN:GetMeter(meterName)
	CurrentX = meter:GetX()

	OpenedSubmenu = meterName

	SKIN:Bang("!ShowMeterGroup", OpenedSubmenu)
	SKIN:Bang("!UpdateGroup", OpenedSubmenu)
end

function RainmeterOnClick () 

	-- close all submenus
	for key,value in ipairs(groups) do
		SKIN:Bang("!HideMeterGroup", value)
	end

	previousOpenedSubmenu = OpenedSubmenu
	OpenedSubmenu = "None"

	-- SKIN:Bang("!Update")
	SKIN:Bang("!Redraw")
end

function CreateMenu (data) 
	local menuMeters = ""
	local submenuMeters = ""

	for key, value in pairs(data) do 
		local name = value["name"]:gsub("%s", "")

		menuMeters = menuMeters .. "\n["..name.."]\n"
		.. "Meter=String\n"
		.. "MeterStyle = GenericMenuButtonStyle\n"
		.. "SolidColor=0,0,0,1\n"
		.. "Padding=10,3,0,3\n"
		.. "Text=" .. value["name"] .. "\n"
		.. "MouseOverAction="
			.. "[!SetOption "..name.." FontColor 255,255,255,255]"
			.. "[!CommandMeasure MenuMaster \"TopMenuOnMouseOver(\'"..name.."\')\"]"
			.. "[!Update]\n"
		.. "MouseLeaveAction=[!SetOption "..name.." FontColor 200,200,200,255][!Update]\n"
		.. "LeftMouseUpAction="
			.. "[!ToggleMeterGroup "..name.."]"
			.. "[!CommandMeasure MenuMaster \"TopMenuOnClick(\'"..name.."\')\"][!Update][!Redraw]\n"
		.. "X=0R\n"
		.. "Y=13\n"

		-- Creates the submenu for the current top menu
		submenuMeters = submenuMeters .. CreateSubMenu(value)
	end

	return menuMeters .. submenuMeters
end

function CreateSubMenu (value)
	local menuMeters = ""

	local topName = value["name"]:gsub("%s", "")
	local submenus = value["submenu"]

	for key, value in pairs(submenus) do 
		local name = value["name"]:gsub("%s", "")
		local path = value["path"] and value["path"] or ""

		menuMeters = menuMeters .. "\n["..name.."]\n"
		.. "Meter=String\n"
		.. "MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle\n"
		.. "Text=" .. value["name"] .. "\n"
		.. "MouseOverAction=[!SetOption "..name.." FontColor 255,255,255,255][!Update]\n"
		.. "MouseLeaveAction=[!SetOption "..name.." FontColor 200,200,200,255][!Update]\n"
		.. "LeftMouseDownAction=["..path.."]\n"
		.. "Group="..topName.."\n"
		.. "Y="..(key == 1 and "42" or "0R").."\n"
		.. "X=[&MenuMaster:CurrentX]\n"
	end
	return menuMeters
end

-- unused // kept for reference
-- function Traverse(table, fn) 
-- 	for key, value in pairs(table) do 
-- 		for tableKey, tableValue in pairs(value) do
-- 			if(tableKey == "submenu") then
-- 				Traverse(tableValue, fn)
-- 			else 
-- 				fn(tableKey, tableValue)
-- 			end
-- 		end
-- 	end
-- end

function ReadFile(FilePath)
	-- HANDLE RELATIVE PATH OPTIONS.
	FilePath = SKIN:MakePathAbsolute(FilePath)

	-- OPEN FILE.
	local File = io.open(FilePath)

	-- HANDLE ERROR OPENING FILE.
	if not File then
		print('ReadFile: unable to open file at ' .. FilePath)
		return
	end

	-- READ FILE CONTENTS AND CLOSE.
	local Contents = File:read('*all')
	File:close()

	return Contents
end