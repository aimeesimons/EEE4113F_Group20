<Qucs Schematic 0.0.19>
<Properties>
  <View=-64,-75,1249,689,0.785225,0,0>
  <Grid=10,10,1>
  <DataSet=Amplifer.dat>
  <DataDisplay=Amplifer.dpl>
  <OpenDisplay=1>
  <Script=Amplifer.m>
  <RunScript=0>
  <showFrame=0>
  <FrameText0=Title>
  <FrameText1=Drawn By:>
  <FrameText2=Date:>
  <FrameText3=Revision:>
</Properties>
<Symbol>
</Symbol>
<Components>
  <Lib OP2 1 290 410 -20 69 0 0 "OpAmps" 0 "tl071(TI)" 0>
  <Lib OP1 1 290 110 -20 -88 1 0 "OpAmps" 0 "tl071(TI)" 0>
  <Lib OP3 1 810 250 -20 69 0 0 "OpAmps" 0 "tl071(TI)" 0>
  <GND * 1 660 530 0 0 0 0>
  <GND * 1 1070 510 0 0 0 0>
  <Vdc V2 1 1010 450 18 -26 0 1 "+2.5 V" 1>
  <Vdc V3 1 1120 450 18 -26 0 1 "-2.5 V" 1>
  <R R4_ 1 240 260 -110 -26 0 3 "1000 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R2 1 520 210 -26 -53 1 0 "1000" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R2_ 1 520 310 -26 15 0 0 "1000" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R __R3__ 1 820 80 -26 15 0 0 "12000 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R3_ 1 660 410 15 -26 0 1 "12000 Ohm" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R1_ 1 380 310 -26 -53 1 0 "49500" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <R R1 1 390 210 -26 -53 1 0 "49500" 1 "26.85" 0 "0.0" 0 "0.0" 0 "26.85" 0 "european" 0>
  <VProbe Pr2 1 0 270 28 -31 0 0>
  <Vdc Vin 1 80 280 18 -26 1 3 "0.2V" 1>
  <Vdc V4 1 140 490 18 -26 0 1 "1 V" 1>
  <GND * 1 80 330 0 0 0 0>
  <GND * 1 140 520 0 0 0 0>
  <VProbe Pr3 1 30 460 28 -31 0 0>
  <.DC DC1 1 790 590 0 39 0 0 "26.85" 0 "0.001" 0 "1 pA" 0 "1 uV" 0 "no" 0 "150" 0 "no" 0 "none" 0 "CroutLU" 0>
</Components>
<Wires>
  <240 150 250 150 "" 0 0 0 "">
  <240 150 240 210 "" 0 0 0 "">
  <240 290 240 310 "" 0 0 0 "">
  <240 370 250 370 "" 0 0 0 "">
  <240 310 240 370 "" 0 0 0 "">
  <240 210 240 230 "" 0 0 0 "">
  <410 310 450 310 "" 0 0 0 "">
  <420 210 450 210 "" 0 0 0 "">
  <550 210 670 210 "" 0 0 0 "">
  <670 210 770 210 "" 0 0 0 "">
  <550 310 660 310 "" 0 0 0 "">
  <660 310 660 380 "" 0 0 0 "">
  <770 290 770 310 "" 0 0 0 "">
  <660 310 770 310 "" 0 0 0 "">
  <900 250 930 250 "" 0 0 0 "">
  <930 80 930 250 "" 0 0 0 "">
  <850 80 930 80 "" 0 0 0 "">
  <1010 480 1010 510 "" 0 0 0 "">
  <1070 510 1120 510 "" 0 0 0 "">
  <1010 510 1070 510 "" 0 0 0 "">
  <1120 480 1120 510 "" 0 0 0 "">
  <380 410 450 410 "" 0 0 0 "">
  <450 310 490 310 "" 0 0 0 "">
  <450 310 450 410 "" 0 0 0 "">
  <380 110 450 110 "" 0 0 0 "">
  <450 210 490 210 "" 0 0 0 "">
  <450 110 450 210 "" 0 0 0 "">
  <80 70 250 70 "" 0 0 0 "">
  <80 70 80 250 "" 0 0 0 "">
  <80 310 80 330 "" 0 0 0 "">
  <660 440 660 530 "" 0 0 0 "">
  <670 80 670 210 "" 0 0 0 "">
  <670 80 790 80 "" 0 0 0 "">
  <240 210 360 210 "" 0 0 0 "">
  <240 310 350 310 "" 0 0 0 "">
  <60 250 80 250 "" 0 0 0 "">
  <60 250 60 290 "" 0 0 0 "">
  <10 290 60 290 "" 0 0 0 "">
  <-10 330 80 330 "" 0 0 0 "">
  <-10 290 -10 330 "" 0 0 0 "">
  <140 450 140 460 "" 0 0 0 "">
  <140 450 250 450 "" 0 0 0 "">
  <40 480 40 510 "" 0 0 0 "">
  <40 510 140 510 "" 0 0 0 "">
  <-30 480 20 480 "" 0 0 0 "">
  <-30 390 -30 480 "" 0 0 0 "">
  <-30 390 140 390 "" 0 0 0 "">
  <140 390 140 450 "" 0 0 0 "">
  <330 370 330 370 "Vplus" 360 340 0 "">
  <330 450 330 450 "Vminus" 350 470 0 "">
  <330 150 330 150 "Vplus" 320 170 0 "">
  <330 70 330 70 "Vminus" 350 20 0 "">
  <850 210 850 210 "Vplus" 860 160 0 "">
  <850 290 850 290 "Vminus" 850 320 0 "">
  <1010 420 1010 420 "Vplus" 1040 390 0 "">
  <1120 420 1120 420 "Vminus" 1150 390 0 "">
  <930 250 930 250 "Output" 960 220 0 "">
</Wires>
<Diagrams>
</Diagrams>
<Paintings>
</Paintings>
