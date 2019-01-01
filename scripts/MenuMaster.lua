loadedMenu = "menu not acquired";

local json = {}
local userCreatedMenusPath = "data/menu.json"
local menusPath = "sections/menus.inc"
local jsonScriptPath = "scripts/json.lua"

local base =   "; DO NOT MANUALLY EDIT\n"
			.. "; ALL EDITS WILL BE LOST ONCE IT DETECTS A NEW BUTTON\n"
			.. "; MenuMaster.lua handles the editing of this file\n" 
			.. "[AddCustomVariables]\n"
			.. "@includeVariables=\"../data/variables.inc\"\n"
			.. "\n[MenuMaster]\n"
			.. "Measure=Script\n"
			.. "ScriptFile=scripts/MenuMaster.lua\n"
			.. "Disabled=1\n"

function Initialize ()
	json = assert(loadfile(SKIN:MakePathAbsolute(jsonScriptPath)))() 
	UpdateMenusMeter()
end

CurrentX = 0
local groups = {}
function SetCurrentX (meterName)
	local meter = SKIN:GetMeter(meterName)
	CurrentX = meter:GetX()
end

function UpdateMenusMeter () 

	-- decode the menu.json
	local data = ReadFile(userCreatedMenusPath)
	data = json.decode(data)
	if not data then return end	

	-- Initialize
	for key, value in pairs(data) do
		table.insert(groups, value["name"])
	end
	local parameters = "\n[Rainmeter]\n"
	-- .. "LeftMouseDownAction=[!CommandMeasure MenuMaster \"testprint()\"]"
	.. "LeftMouseDownAction="
	for key, value in pairs(groups) do 
		parameters = parameters .. "["
		parameters = parameters .. "!HideMeterGroup " .. value
		parameters = parameters .. "]"
	end
	base = base .. parameters .. "[!Redraw]\n"
	
	-- OPEN FILE.
	local file = io.open(SKIN:MakePathAbsolute(menusPath), "w+")

	-- HANDLE ERROR OPENING FILE.
	if not file then
		print('ReadFile: unable to open file at ' .. menusPath)
		return
	end

	-- build the menu
	local newMenuMeters = base .. CreateTopMenu(data)
	io.output(file)
	io.write(newMenuMeters)
	io.close(file)
end

function testprint()
	print(SKIN:GetMeter("Development"):GetOption("SolidColor", ""))
end

function CreateTopMenu (data) 
	local menuMeters = ""
	local submenuMeters = ""

	for key, value in pairs(data) do 
		local name = value["name"]:gsub("%s", "")
		local textName = value["name"]

		menuMeters = menuMeters .. "\n["..name.."]\n"
		.. "Meter=String\n"
		.. "FontColor=200,200,200,255\n"
		.. "FontSize= 11\n"
		.. "FontWeight=400\n"
		.. "FontFace=Roboto\n"
		.. "AntiAlias=1\n"
		.. "StringAlign=LeftCenter\n"
		.. "SolidColor=0,0,0,1\n"
		.. "Padding=10,3,0,3\n"
		.. "ClipString=1\n"
		.. "Text=" .. name .. "\n"
		.. "MouseOverAction=[!SetOption "..name.." FontColor 255,255,255,255][!Update]\n"
		.. "MouseLeaveAction=[!SetOption "..name.." FontColor 200,200,200,255][!Update]\n"
		.. "LeftMouseUpAction="
		.. "[!ToggleMeterGroup "..textName.."]"
		.. "[!CommandMeasure MenuMaster \"SetCurrentX(\'"..name.."\')\"][!Update][!Redraw]\n"
		.. "X=0R\n"
		.. "Y=13\n"

		submenuMeters = submenuMeters .. CreateSubMenu(value)
	end

	return menuMeters .. submenuMeters
end

function CloseOtherGroups () 
	local parameters = ""
	for key, value in pairs(groups) do 
		parameters = parameters .. "["
		parameters = parameters .. "!HideMeterGroup " .. value
		parameters = parameters .. "]"
	end
	parameters = parameters .. "[!Update][!Redraw]\n"
	return parameters
end

function CreateSubMenu (value)
	local menuMeters = ""

	local topName = value["name"]:gsub("%s", "")
	local submenus = value["submenu"]

	for key, value in pairs(submenus) do 
		local name = value["name"]:gsub("%s", "")
		local textName = value["name"]
		local path = value["path"] and value["path"] or ""

		menuMeters = menuMeters .. "\n["..name.."]\n"
		.. "Meter=String\n"
		.. "FontColor=200,200,200,255\n"
		.. "FontSize= 11\n"
		.. "FontWeight=400\n"
		.. "FontFace=Roboto\n"
		.. "AntiAlias=1\n"
		.. "StringAlign=LeftCenter\n"
		.. "SolidColor=#BackgroundColor#\n"
		.. "Padding=10,3,0,3\n"
		.. "ClipString=1\n"
		.. "Text=" .. textName .. "\n"
		.. "MouseOverAction=[!SetOption "..name.." FontColor 255,255,255,255][!Update]\n"
		.. "MouseLeaveAction=[!SetOption "..name.." FontColor 200,200,200,255][!Update]\n"
		.. "LeftMouseDownAction=["..path.."]"..CloseOtherGroups()
		.. "Group="..topName.."\n"
		.. "DynamicVariables=1\n"
		.. "W=250\n"
		.. "H=25\n"
		.. "Y="..(key == 1 and "42" or "0R").."\n"
		.. "X=[&MenuMaster:CurrentX]\n"
		.. "Hidden=1\n"
	end
	return menuMeters
end

-- unused
function Traverse(table, fn) 
	for key, value in pairs(table) do 
		for tableKey, tableValue in pairs(value) do
			if(tableKey == "submenu") then
				Traverse(tableValue, fn)
			else 
				fn(tableKey, tableValue)
			end
		end
	end
end

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