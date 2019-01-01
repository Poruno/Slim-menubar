[AddCustomVariables]
@includeVariables="../data/variables.inc"

[MeasureTime]
Measure=Time
Format="%A, %B %#d, %Y %#I:%M %p"

[Clock]
Meter=String
X=(#WORKAREAWIDTH#)
Y=13
Padding=0,0,(#PaddingRight#+3),0
FontColor=200,200,200,255
FontSize=11
FontWeight=400
FontFace=Roboto
AntiAlias=1
MeasureName=MeasureTime
StringAlign=RightCenter