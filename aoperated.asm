mov A, #25H
mov B, #12H
add A,B
mov 40H,A
mov A,#25H
subb A,B
mov 41H,A
mov A,#25H
MUL AB
mov 42H,A
mov 43H,B
mov A,#25H
mov B,#12H
div AB
mov 44H,A
mov 45H,B
end