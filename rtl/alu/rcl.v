task do_rcl;
    output [15:0] out;
    input is_8_bit;
    input [15:0] a;
    input [15:0] b;
    input [15:0] flags_in;
    output [15:0] flags_out;

    begin
        flags_out = flags_in;
        if (!is_8_bit) begin
            reg [4:0] i;
            out = a;
            for (i = 5'b0; i < b[4:0]; ++i) begin
                {flags_out[CF_IDX], out} = {out[15:0], flags_out[CF_IDX]};
            end
        end else begin
            reg [4:0] i;
            out = {8'b0, a[7:0]};
            for (i = 5'b0; i < b[4:0]; ++i) begin
                {flags_out[CF_IDX], out[7:0]} = {out[7:0], flags_out[CF_IDX]};
            end
        end
        flags_out[OF_IDX] = is_8_bit ? a[7] ^ a[6] : a[15] ^ a[14];
        shift_flags(flags_out, is_8_bit, out, a, b);

        if (~|b)
            flags_out = flags_in;
    end
endtask