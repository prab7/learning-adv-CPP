entity helloTb is
end entity;

architecture sim of helloTb is
begin

    process is
    begin 
        
        report "Hello World";
        wait;

    end process;

end architecture; 

