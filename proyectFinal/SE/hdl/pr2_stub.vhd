-------------------------------------------------------------------------------
-- pr2_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity pr2_stub is
  port (
    Rx : in std_logic;
    Tx : out std_logic;
    leds : inout std_logic_vector(0 to 7);
    Clk : in std_logic;
    reset : in std_logic;
    Sw : in std_logic_vector(0 to 2);
    banner_0_col_serial_out_pin : out std_logic;
    banner_0_col_clk_pin : out std_logic;
    banner_0_row_serial_out_pin : out std_logic;
    banner_0_row_clk_pin : out std_logic;
    banner_0_reset_out_pin : out std_logic;
    keypad_0_S_pin : out std_logic_vector(3 downto 0);
    keypad_0_R_pin : in std_logic_vector(3 downto 0);
    ledsrgb_0_red_pin : out std_logic;
    ledsrgb_0_blue_pin : out std_logic;
    ledsrgb_0_green_pin : out std_logic;
    banner_0_reset2_out_pin : out std_logic;
    altavoz_0_sonido_pin : out std_logic;
    motor_hw_0_control_motor_pin : out std_logic_vector(0 to 3)
  );
end pr2_stub;

architecture STRUCTURE of pr2_stub is

  component pr2 is
    port (
      Rx : in std_logic;
      Tx : out std_logic;
      leds : inout std_logic_vector(0 to 7);
      Clk : in std_logic;
      reset : in std_logic;
      Sw : in std_logic_vector(0 to 2);
      banner_0_col_serial_out_pin : out std_logic;
      banner_0_col_clk_pin : out std_logic;
      banner_0_row_serial_out_pin : out std_logic;
      banner_0_row_clk_pin : out std_logic;
      banner_0_reset_out_pin : out std_logic;
      keypad_0_S_pin : out std_logic_vector(3 downto 0);
      keypad_0_R_pin : in std_logic_vector(3 downto 0);
      ledsrgb_0_red_pin : out std_logic;
      ledsrgb_0_blue_pin : out std_logic;
      ledsrgb_0_green_pin : out std_logic;
      banner_0_reset2_out_pin : out std_logic;
      altavoz_0_sonido_pin : out std_logic;
      motor_hw_0_control_motor_pin : out std_logic_vector(0 to 3)
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of pr2 : component is "user_black_box";

begin

  pr2_i : pr2
    port map (
      Rx => Rx,
      Tx => Tx,
      leds => leds,
      Clk => Clk,
      reset => reset,
      Sw => Sw,
      banner_0_col_serial_out_pin => banner_0_col_serial_out_pin,
      banner_0_col_clk_pin => banner_0_col_clk_pin,
      banner_0_row_serial_out_pin => banner_0_row_serial_out_pin,
      banner_0_row_clk_pin => banner_0_row_clk_pin,
      banner_0_reset_out_pin => banner_0_reset_out_pin,
      keypad_0_S_pin => keypad_0_S_pin,
      keypad_0_R_pin => keypad_0_R_pin,
      ledsrgb_0_red_pin => ledsrgb_0_red_pin,
      ledsrgb_0_blue_pin => ledsrgb_0_blue_pin,
      ledsrgb_0_green_pin => ledsrgb_0_green_pin,
      banner_0_reset2_out_pin => banner_0_reset2_out_pin,
      altavoz_0_sonido_pin => altavoz_0_sonido_pin,
      motor_hw_0_control_motor_pin => motor_hw_0_control_motor_pin
    );

end architecture STRUCTURE;

