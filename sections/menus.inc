; DO NOT MANUALLY EDIT
; ALL EDITS WILL BE LOST ONCE IT DETECTS A NEW BUTTON
; MenuMaster.lua handles the editing of this file
[AddCustomVariables]
@includeVariables="../data/variables.inc"

[MenuMaster]
Measure=Script
ScriptFile=scripts/MenuMaster.lua
Disabled=1

[Rainmeter]
LeftMouseDownAction=[!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Redraw]

[All]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=0,0,0,1
Padding=10,3,0,3
ClipString=1
Text=All
MouseOverAction=[!SetOption All FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption All FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup All][!CommandMeasure MenuMaster "SetCurrentX('All')"][!Update][!Redraw]
X=0R
Y=13

[Internet]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=0,0,0,1
Padding=10,3,0,3
ClipString=1
Text=Internet
MouseOverAction=[!SetOption Internet FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Internet FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Internet][!CommandMeasure MenuMaster "SetCurrentX('Internet')"][!Update][!Redraw]
X=0R
Y=13

[Games]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=0,0,0,1
Padding=10,3,0,3
ClipString=1
Text=Games
MouseOverAction=[!SetOption Games FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Games FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Games][!CommandMeasure MenuMaster "SetCurrentX('Games')"][!Update][!Redraw]
X=0R
Y=13

[Graphics]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=0,0,0,1
Padding=10,3,0,3
ClipString=1
Text=Graphics
MouseOverAction=[!SetOption Graphics FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Graphics FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Graphics][!CommandMeasure MenuMaster "SetCurrentX('Graphics')"][!Update][!Redraw]
X=0R
Y=13

[Media]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=0,0,0,1
Padding=10,3,0,3
ClipString=1
Text=Media
MouseOverAction=[!SetOption Media FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Media FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Media][!CommandMeasure MenuMaster "SetCurrentX('Media')"][!Update][!Redraw]
X=0R
Y=13

[Productivity]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=0,0,0,1
Padding=10,3,0,3
ClipString=1
Text=Productivity
MouseOverAction=[!SetOption Productivity FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Productivity FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Productivity][!CommandMeasure MenuMaster "SetCurrentX('Productivity')"][!Update][!Redraw]
X=0R
Y=13

[Development]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=0,0,0,1
Padding=10,3,0,3
ClipString=1
Text=Development
MouseOverAction=[!SetOption Development FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Development FontColor 200,200,200,255][!Update]
LeftMouseUpAction=[!ToggleMeterGroup Development][!CommandMeasure MenuMaster "SetCurrentX('Development')"][!Update][!Redraw]
X=0R
Y=13

[MyComputer]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=My Computer
MouseOverAction=[!SetOption MyComputer FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption MyComputer FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[shell:mycomputerfolder][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=All
DynamicVariables=1
W=250
H=25
Y=42
X=[&MenuMaster:CurrentX]
Hidden=1

[Run]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Run
MouseOverAction=[!SetOption Run FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Run FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[C:\windows\system32\rundll32.exe shell32.dll,#61][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=All
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[CommandPrompt]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Command Prompt
MouseOverAction=[!SetOption CommandPrompt FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption CommandPrompt FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[cmd][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=All
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[ControlPanel]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Control Panel
MouseOverAction=[!SetOption ControlPanel FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption ControlPanel FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[control][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=All
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[TaskManager]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Task Manager
MouseOverAction=[!SetOption TaskManager FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption TaskManager FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[taskmgr][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=All
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[GoogleChrome]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Google Chrome
MouseOverAction=[!SetOption GoogleChrome FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption GoogleChrome FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[chrome][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Internet
DynamicVariables=1
W=250
H=25
Y=42
X=[&MenuMaster:CurrentX]
Hidden=1

[MozillaFirefox]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Mozilla Firefox
MouseOverAction=[!SetOption MozillaFirefox FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption MozillaFirefox FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[firefox][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Internet
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[InternetExplorer]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Internet Explorer
MouseOverAction=[!SetOption InternetExplorer FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption InternetExplorer FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[iexplore][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Internet
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[Discord]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Discord
MouseOverAction=[!SetOption Discord FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Discord FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[discord/path][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Games
DynamicVariables=1
W=250
H=25
Y=42
X=[&MenuMaster:CurrentX]
Hidden=1

[Steam]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Steam
MouseOverAction=[!SetOption Steam FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Steam FontColor 200,200,200,255][!Update]
LeftMouseDownAction=["E:\Program Files (x86)\Steam\Steam.exe"][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Games
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[AdobePhotoshop]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Adobe Photoshop
MouseOverAction=[!SetOption AdobePhotoshop FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption AdobePhotoshop FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[photoshop/path][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Graphics
DynamicVariables=1
W=250
H=25
Y=42
X=[&MenuMaster:CurrentX]
Hidden=1

[AdobeIllustrator]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Adobe Illustrator
MouseOverAction=[!SetOption AdobeIllustrator FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption AdobeIllustrator FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[illustrator/path][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Graphics
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[VisualStudioCode]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Visual Studio Code
MouseOverAction=[!SetOption VisualStudioCode FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption VisualStudioCode FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[visualstudiocode/path][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Development
DynamicVariables=1
W=250
H=25
Y=42
X=[&MenuMaster:CurrentX]
Hidden=1

[VisualStudio2018]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Visual Studio 2018
MouseOverAction=[!SetOption VisualStudio2018 FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption VisualStudio2018 FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[visualstudio2018/path][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Development
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1

[Notepad]
Meter=String
FontColor=200,200,200,255
FontSize= 11
FontWeight=400
FontFace=Roboto
AntiAlias=1
StringAlign=LeftCenter
SolidColor=#BackgroundColor#
Padding=10,3,0,3
ClipString=1
Text=Notepad
MouseOverAction=[!SetOption Notepad FontColor 255,255,255,255][!Update]
MouseLeaveAction=[!SetOption Notepad FontColor 200,200,200,255][!Update]
LeftMouseDownAction=[notepad][!HideMeterGroup All][!HideMeterGroup Internet][!HideMeterGroup Games][!HideMeterGroup Graphics][!HideMeterGroup Media][!HideMeterGroup Productivity][!HideMeterGroup Development][!Update][!Redraw]
Group=Development
DynamicVariables=1
W=250
H=25
Y=0R
X=[&MenuMaster:CurrentX]
Hidden=1
