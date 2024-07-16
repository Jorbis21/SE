-- Pablo García Fernández y Javier Orbis Ramírez
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.std_logic_unsigned.all;

entity inc_dec is

port (sw : in std_logic;
		clk : in std_logic;
		outLeds : out std_logic_vector (7 downto 0);
		outDisIz : out std_logic_vector (7 downto 0);
		outDisDr : out std_logic_vector (7 downto 0);
		rst : in STD_LOGIC);
end inc_dec;

architecture beh of inc_dec is

--declaracion reloj 1hz
component divisor1
port(
	rst: in STD_LOGIC;
	clk_in : in STD_LOGIC;
	clk_out : out STD_LOGIC
);
end component;

component bin5_to_7segsb
port (
	Entrada0:	in 	STD_LOGIC ;
	Entrada1:	in 	STD_LOGIC ;
	Entrada2:	in 	STD_LOGIC ;
	Entrada3:	in 	STD_LOGIC ;
	Entrada4:	in 	STD_LOGIC ;
	LED0:	out	STD_LOGIC ;
	LED1:	out	STD_LOGIC ;
	LED2:	out	STD_LOGIC ;
	LED3:	out	STD_LOGIC ;
	LED4:	out	STD_LOGIC ;
	LED5:	out	STD_LOGIC ;
	LED6:	out	STD_LOGIC ;
	LED7:	out	STD_LOGIC 
    );
end component;

--señal del reloj de 1hz
signal clk_1hz : std_logic;
signal leds : std_logic_vector (7 downto 0);

--displays
signal izq : std_logic_vector(3 downto 0);
signal der : std_logic_vector(3 downto 0);
signal izqDis : std_logic_vector(7 downto 0);
signal derDis : std_logic_vector(7 downto 0);

begin
--instantación reloj de 1Hz
reloj1sec : divisor1 port map(
		rst => rst,
		clk_in => clk,
		clk_out => clk_1hz
);

displayIzq : bin5_to_7segsb port map(
	Entrada0=> not izq(0),
	Entrada1=>  not izq(1),
	Entrada2=>  not izq(2),
	Entrada3=>  not izq(3),
	Entrada4=>'0',
	LED0=>izqDis(0),
	LED1=>izqDis(1),
	LED2=>izqDis(2),
	LED3=>izqDis(3),
	LED4=>izqDis(4),
	LED5=>izqDis(5),
	LED6=>izqDis(6),
	LED7=>izqDis(7)
);

displayDer : bin5_to_7segsb port map(
	Entrada0=>  not der(0),
	Entrada1=>  not der(1),
	Entrada2=>  not der(2),
	Entrada3=>  not der(3),
	Entrada4=>'0',
	LED0=>derDis(0),
	LED1=>derDis(1),
	LED2=>derDis(2),
	LED3=>derDis(3),
	LED4=>derDis(4),
	LED5=>derDis(5),
	LED6=>derDis(6),
	LED7=>derDis(7)
);

magic: process(clk_1hz)
begin

if rising_edge(clk_1hz) then
	if sw = '1' then
	--incrementa
		if leds = "11111111" then
			leds <= (others=>'0');
		else
			leds <= leds + '1';
		end if;		
	else
	--decrementa 
		if leds = "00000000" then
			leds <= (others=>'1');
		else
			leds <= leds - '1';
		end if;
		
	end if;
	izq <= leds(7 downto 4);
   der <= leds(3 downto 0);
	
	outDisIz <= izqDis;
	outDisDr <= derDis;
	
	outLeds <= not leds;
	
end if;
end process magic;

end beh;
