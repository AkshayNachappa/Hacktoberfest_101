module comb(input a, b, c, d,
            output y);
    assign y = (a ^ b) | (c & d);
endmodule

module comb_tb;
    reg a, b, c, d;
    wire y;
    integer i;

    comb uut(.a(a), .b(b), .c(c), .d(d), .y(y));

    initial begin
        a <= 0;
        b <= 0;
        c <= 0;
        d <= 0;

        $monitor("a = %b    b = %b    c = %b    d = %b    y = %b\n", a, b, c, d, y);

        for(i = 0; i < 16; i = i + 1) begin
            {a, b, c, d} = i;
            #10;
        end
    end
endmodule