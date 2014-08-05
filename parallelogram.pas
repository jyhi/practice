var l, w, i ,tmp: integer;

begin
    write ( 'Input the height of parallelogram: ' );
    readln ( l );
    write ( 'Input the width of parallelogram: ' );
    readln ( w );
    
    for i := 1 to l do
    begin
        for tmp := l downto i do
            write ( ' ' );
        for tmp := 1 to w do
            write ( '@' );
        writeln;
    end;
end.
