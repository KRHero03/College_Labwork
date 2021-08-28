proctype A(byte state; short foo)
{
    (state == 1) -> state = foo
}

init
{
    run A(1, 3)
}
