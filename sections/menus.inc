; DO NOT MANUALLY EDIT
; ALL EDITS WILL BE LOST ONCE IT DETECTS A NEW BUTTON
; MenuMaster.lua handles the editing of this file

[Rainmeter]
LeftMouseUpAction=[!CommandMeasure MenuMaster "RainmeterOnClick()"]

[AddCustomVariables]
@includeVariables="../data/variables.inc"

[MenuMaster]
Measure=Script
ScriptFile=scripts/MenuMaster.lua
Disabled=1

[GenericMenuButtonStyle]
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
ClipString=1

[GenericSubmenuButtonStyle]
SolidColor=#BackgroundColor#
Padding=10,3,0,3
DynamicVariables=1
W=250
H=25
Hidden=1

[PaddingLeft]
Meter=String
X=#PaddingLeft#
Y=(#PaddingTop#+4)
W=25
H=25

[All]
Meter=String
MeterStyle = GenericMenuButtonStyle
SolidColor=0,0,0,1
Padding=10,3,0,3
Text=All
MouseOverAction=[!SetOption All FontColor 255,255,255,255][!CommandMeasure MenuMaster "TopMenuOnMouseOver('All')"][!Update]
MouseLeaveAction=[!SetOption All FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup All][!CommandMeasure MenuMaster "TopMenuOnClick('All')"][!Update][!Redraw]
X=0R
Y=13

[Internet]
Meter=String
MeterStyle = GenericMenuButtonStyle
SolidColor=0,0,0,1
Padding=10,3,0,3
Text=Internet
MouseOverAction=[!SetOption Internet FontColor 255,255,255,255][!CommandMeasure MenuMaster "TopMenuOnMouseOver('Internet')"][!Update]
MouseLeaveAction=[!SetOption Internet FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Internet][!CommandMeasure MenuMaster "TopMenuOnClick('Internet')"][!Update][!Redraw]
X=0R
Y=13

[Games]
Meter=String
MeterStyle = GenericMenuButtonStyle
SolidColor=0,0,0,1
Padding=10,3,0,3
Text=Games
MouseOverAction=[!SetOption Games FontColor 255,255,255,255][!CommandMeasure MenuMaster "TopMenuOnMouseOver('Games')"][!Update]
MouseLeaveAction=[!SetOption Games FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Games][!CommandMeasure MenuMaster "TopMenuOnClick('Games')"][!Update][!Redraw]
X=0R
Y=13

[Graphics]
Meter=String
MeterStyle = GenericMenuButtonStyle
SolidColor=0,0,0,1
Padding=10,3,0,3
Text=Graphics
MouseOverAction=[!SetOption Graphics FontColor 255,255,255,255][!CommandMeasure MenuMaster "TopMenuOnMouseOver('Graphics')"][!Update]
MouseLeaveAction=[!SetOption Graphics FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Graphics][!CommandMeasure MenuMaster "TopMenuOnClick('Graphics')"][!Update][!Redraw]
X=0R
Y=13

[Development]
Meter=String
MeterStyle = GenericMenuButtonStyle
SolidColor=0,0,0,1
Padding=10,3,0,3
Text=Development
MouseOverAction=[!SetOption Development FontColor 255,255,255,255][!CommandMeasure MenuMaster "TopMenuOnMouseOver('Development')"][!Update]
MouseLeaveAction=[!SetOption Development FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Development][!CommandMeasure MenuMaster "TopMenuOnClick('Development')"][!Update][!Redraw]
X=0R
Y=13

[MyComputer]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=My Computer
MouseOverAction=[!SetOption MyComputer FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption MyComputer FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[shell:mycomputerfolder]
Group=All
Y=42
X=[&MenuMaster:CurrentX]

[CommandPrompt]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Command Prompt
MouseOverAction=[!SetOption CommandPrompt FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption CommandPrompt FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[cmd]
Group=All
Y=0R
X=[&MenuMaster:CurrentX]

[ControlPanel]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Control Panel
MouseOverAction=[!SetOption ControlPanel FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption ControlPanel FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[control]
Group=All
Y=0R
X=[&MenuMaster:CurrentX]

[TaskManager]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Task Manager
MouseOverAction=[!SetOption TaskManager FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption TaskManager FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[taskmgr]
Group=All
Y=0R
X=[&MenuMaster:CurrentX]

[GoogleChrome]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Google Chrome
MouseOverAction=[!SetOption GoogleChrome FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption GoogleChrome FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[chrome]
Group=Internet
Y=42
X=[&MenuMaster:CurrentX]

[MozillaFirefox]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Mozilla Firefox
MouseOverAction=[!SetOption MozillaFirefox FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption MozillaFirefox FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[firefox]
Group=Internet
Y=0R
X=[&MenuMaster:CurrentX]

[InternetExplorer]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Internet Explorer
MouseOverAction=[!SetOption InternetExplorer FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption InternetExplorer FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[iexplore]
Group=Internet
Y=0R
X=[&MenuMaster:CurrentX]

[Discord]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Discord
MouseOverAction=[!SetOption Discord FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Discord FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[discord/path]
Group=Games
Y=42
X=[&MenuMaster:CurrentX]

[Steam]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Steam
MouseOverAction=[!SetOption Steam FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Steam FontColor 200,200,200,255][!Update]
LeftMouseDownAction=["E:\Program Files (x86)\Steam\Steam.exe"]
Group=Games
Y=0R
X=[&MenuMaster:CurrentX]

[AdobePhotoshop]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Adobe Photoshop
MouseOverAction=[!SetOption AdobePhotoshop FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption AdobePhotoshop FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[photoshop/path]
Group=Graphics
Y=42
X=[&MenuMaster:CurrentX]

[AdobeIllustrator]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Adobe Illustrator
MouseOverAction=[!SetOption AdobeIllustrator FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption AdobeIllustrator FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[illustrator/path]
Group=Graphics
Y=0R
X=[&MenuMaster:CurrentX]

[VisualStudioCode]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Visual Studio Code
MouseOverAction=[!SetOption VisualStudioCode FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption VisualStudioCode FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[visualstudiocode/path]
Group=Development
Y=42
X=[&MenuMaster:CurrentX]

[VisualStudio2018]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Visual Studio 2018
MouseOverAction=[!SetOption VisualStudio2018 FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption VisualStudio2018 FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[visualstudio2018/path]
Group=Development
Y=0R
X=[&MenuMaster:CurrentX]

[Notepad]
Meter=String
MeterStyle = GenericMenuButtonStyle | GenericSubmenuButtonStyle
Text=Notepad
MouseOverAction=[!SetOption Notepad FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Notepad FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[notepad]
Group=Development
Y=0R
X=[&MenuMaster:CurrentX]
