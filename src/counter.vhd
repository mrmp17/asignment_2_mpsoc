
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values


-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity counter is
    Port ( clk : in STD_LOGIC;
           counter_out : out STD_LOGIC_VECTOR (31 downto 0));
end counter;


architecture Behavioral of counter is
signal count_sig: unsigned( 31 downto 0) := x"00000000";


begin
    
	process(clk)
	begin
        	if(rising_edge(clk))then
			count_sig<=count_sig+1;	            
               end if;
        end process;
        
	counter_out<=std_logic_vector(count_sig);
            
end Behavioral;
