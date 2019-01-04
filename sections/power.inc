[AddCustomVariables]
@includeVariables="../data/variables.inc"

[MenuPowerButton]
Meter=Button
ButtonImage=#@#Icons\power-off.png
x=#PaddingLeft#
y=(#PaddingTop#+4)
Greyscale=1
ImageTint=#PowerColor#
LeftMouseUpAction=[!ToggleMeter ShutdownBackground][!ToggleMeter ShutdownButton][!ToggleMeter ShutdownWord]

[ShutdownBackground]
Meter=Shape 
Shape= Rectangle 0,0, #SCREENAREAWIDTH#, #SCREENAREAHEIGHT#| StrokeWidth 0 | Fill Color #ShutdownBackgroundColor#
LeftMouseUpAction=[!ToggleMeter ShutdownBackground][!ToggleMeter ShutdownButton][!ToggleMeter ShutdownWord][!Redraw]
Hidden=1

[ShutdownButton]
Meter = Shape
Shape= Line (#SCREENAREAWIDTH#/2),(#SCREENAREAHEIGHT#/2-90),(#SCREENAREAWIDTH#/2),(#SCREENAREAHEIGHT#/2),90,90 | Extend SharedModifiers
Shape2= Arc (#SCREENAREAWIDTH#/2 - 50),(#SCREENAREAHEIGHT#/2 - 60),(#SCREENAREAWIDTH#/2 + 50),(#SCREENAREAHEIGHT#/2- 60), 80, 80, 0, 1, 1, 0 | Extend SharedModifiers
SharedModifiers =  StrokeWidth 30 | StrokeColor #ShutdownColor# | Fill Color 0,0,0,0
Greyscale = 1
Imagetint = 1
MouseOverAction = [!HideMeter ShutdownButton][!ShowMeter HoveredShutdownButton][!SetOption ShutdownWord FontColor #HoveredShutdownColor#][!Update][!Redraw]
Hidden=1

[HoveredShutdownButton]
Meter = Shape
Shape= Line (#SCREENAREAWIDTH#/2),(#SCREENAREAHEIGHT#/2-90),(#SCREENAREAWIDTH#/2),(#SCREENAREAHEIGHT#/2),90,90 | Extend SharedModifiers
Shape2= Arc (#SCREENAREAWIDTH#/2 - 50),(#SCREENAREAHEIGHT#/2 - 60),(#SCREENAREAWIDTH#/2 + 50),(#SCREENAREAHEIGHT#/2- 60), 80, 80, 0, 1, 1, 0 | Extend SharedModifiers
SharedModifiers =  StrokeWidth 30 | StrokeColor #HoveredShutdownColor# | Fill Color 0,0,0,0
Greyscale = 1
Imagetint = 1
MouseLeaveAction =  [!ShowMeter ShutdownButton][!HideMeter HoveredShutdownButton][!SetOption ShutdownWord FontColor #ShutdownColor#][!Update][!Redraw]
Hidden=1

[ShutdownWord]
Meter=String
Text="SHUTDOWN"
x = (#SCREENAREAWIDTH#/2 - 56)
y = (#SCREENAREAHEIGHT#/2 + 110)
FontColor=#ShutdownColor#
FontSize= 14
FontWeight=600
FontFace=Roboto
AntiAlias=1
Case= Upper
Hidden=1