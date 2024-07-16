-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    Rst_pin : in std_logic;
    RX_pin : in std_logic;
    TX_pin : out std_logic;
    control_motor : out std_logic_vector(0 to 3);
    keypad_0_R_pin : in std_logic_vector(3 downto 0);
    keypad_0_S_pin : out std_logic_vector(3 downto 0);
    lcd_rw : out std_logic;
    lcd_rs : out std_logic;
    lcd_e : out std_logic;
    lcd_data : out std_logic_vector(7 downto 0);
    leds_red : out std_logic;
    leds_green : out std_logic;
    leds_blue : out std_logic;
    Clk_pin : in std_logic;
    sonido : out std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      Rst_pin : in std_logic;
      RX_pin : in std_logic;
      TX_pin : out std_logic;
      control_motor : out std_logic_vector(0 to 3);
      keypad_0_R_pin : in std_logic_vector(3 downto 0);
      keypad_0_S_pin : out std_logic_vector(3 downto 0);
      lcd_rw : out std_logic;
      lcd_rs : out std_logic;
      lcd_e : out std_logic;
      lcd_data : out std_logic_vector(7 downto 0);
      leds_red : out std_logic;
      leds_green : out std_logic;
      leds_blue : out std_logic;
      Clk_pin : in std_logic;
      sonido : out std_logic
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      Rst_pin => Rst_pin,
      RX_pin => RX_pin,
      TX_pin => TX_pin,
      control_motor => control_motor,
      keypad_0_R_pin => keypad_0_R_pin,
      keypad_0_S_pin => keypad_0_S_pin,
      lcd_rw => lcd_rw,
      lcd_rs => lcd_rs,
      lcd_e => lcd_e,
      lcd_data => lcd_data,
      leds_red => leds_red,
      leds_green => leds_green,
      leds_blue => leds_blue,
      Clk_pin => Clk_pin,
      sonido => sonido
    );

end architecture STRUCTURE;

