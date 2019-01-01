[AddCustomVariables]
@includeVariables="../data/variables.inc"

[ShutdownBackground]
Meter=Button 
Shape= Rectangle 0,0,#WORKAREAWIDTH#,#WORKAREAHEIGHT#| StrokeWidth 0 | Fill Color #BackgroundColor#
SolidColor= #BackgroundColor#
W=#WORKAREAWIDTH#
H=#WORKAREAHEIGHT#
LeftMouseUpAction=[!ToggleMeter ShutdownButton][!ToggleMeter ShutdownBackground][!UpdateMeter ShutdownBackground][!Redraw]
Hidden=1

[ShutdownButton]
Meter=Button
ButtonImage=#@#Icons\shutdown.png
x = (#WORKAREAWIDTH#/2-#ConfirmSizeBox#/2+8)
y = (#WORKAREAHEIGHT#/2-#ConfirmSizeBox#/2+9)
Greyscale=1
ImageTint=#ShutdownColor#
Hidden=1

[MenuPowerButton]
Meter=Button
ButtonImage=#@#Icons\power-off.png
x=#PaddingLeft#
y=(#PaddingTop#+4)
Greyscale=1
ImageTint=#PowerColor#
LeftMouseUpAction=[!ToggleMeter ShutdownButton][!ToggleMeter ShutdownBackground][!UpdateMeter ShutdownBackground][!Redraw]

; [ShutdownWord]
; Meter=String
; Text="SHUTDOWN"
; x = (#WORKAREAWIDTH#/2-#ConfirmSizeBox#/2+8)
; y = #ConfirmSizeBox#
; FontSize= 11
; FontWeight=400
; FontFace=Roboto
; AntiAlias=1
; Greyscale=1
; ImageTint=#ShutdownColor#
; Hidden=1