#	push_swap 42

<div style="display: flex; align-items: center;">
  <div style="flex: 1; text-align: right;">
    <img src="https://github.com/Cimex404/42-push_swap/blob/master/pushswap_icon.png" align="right" alt="push_swap Logo" width="180">
  </div>
  <div style="flex: 2;">
    <p>
      Push_swap is a 42 project that teaches about algorithms.
    </p>
    <p>
      This project creates an executable called "push_swap" and a checker program called "checker".
      The projects provides two stacks we can use to store the numbers in:
    </p>
  </div>
</div>

```
Stack a:	Is filled with all the inputs that are given to the program as arguments.
Stack b:	Is set to be empty at the beginning.
```

The program uses following operations to manage the stacks and sort the numbers:
```
pa	->	push to first value from stack b to stack a.
pb	->	push to first value from stack a to stack b.
sa	->	swap the first two values of stack a.
sb	->	swap the first two values of stack b.
ss	->	swap the first two values of both stacks (sa and sb combined into a single operation).
ra	->	rotate stack a (first number becomes the last, second becomes first).
rb	->	rotate stack b (first number becomes the last, second becomes first).
rr	->	rotate both stacks at the same time with a single operation.
rra	->	reverse-rotate stack a (last number becomes first, first becomes second).
rrb	->	reverse-rotate stack b (last number becomes first, first becomes second).
rrr	->	reverse-rotate both stacks at the same tie with a single operation.
```

##	How to run
You can run push_swap in any of these ways:
```
./push_swap 1 4 7
./push_swap "2 5 8"
./push_swap "3 6 9" 1 4 7 '2 5 8'
```

##	Checker program
Included is also a checker program that will take the same numbers as the push_swap executable,
as well as the piped output of the push_swap executable and check if the output of push_swap correctly sorts the numbers.
It will display "OK" in case of success, "KO" in case of failure and "Error" in case of invalid input.
It is run as follows:
```
ARG="1 4 7 8 5 2 0 3 6 9"; ./push_swap $ARG | ./checker $ARG
```
