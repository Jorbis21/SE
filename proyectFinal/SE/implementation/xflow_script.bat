@ECHO OFF
@REM ###########################################
@REM # Script file to run the flow 
@REM # 
@REM ###########################################
@REM #
@REM # Command line for ngdbuild
@REM #
ngdbuild -p xc3s1000ft256-5 -nt timestamp -bm pr2.bmm "C:/Users/marti/OneDrive/Documentos/4/proyectFinal/SE/implementation/pr2.ngc" -uc pr2.ucf pr2.ngd 

@REM #
@REM # Command line for map
@REM #
map -o pr2_map.ncd -pr b -ol high -timing -detail pr2.ngd pr2.pcf 

@REM #
@REM # Command line for par
@REM #
par -w -ol high pr2_map.ncd pr2.ncd pr2.pcf 

@REM #
@REM # Command line for post_par_trce
@REM #
trce -e 3 -xml pr2.twx pr2.ncd pr2.pcf 

