
CL-USER 1 > (+ 1 2)
3

CL-USER 2 > (- (+ 3 (* 7 6) 5 (/ 4 2)) 30 22)
0

CL-USER 3 > (- (/ (/ 20 2) (/ 15 3)) 1)
1

CL-USER 4 > (- (+ 3 5 6 2) 1)
15

CL-USER 5 > (- (+ (+ 3 5 6) 2) 1)
15

CL-USER 6 > (/ (+ 3 5 6) (- 2 1))
14

CL-USER 7 > (* (+ 8 2) 5)
50

CL-USER 8 > (/ (- (+ 29 11) (- 2 4)) (* 6 7))
1

CL-USER 9 > (2 -2 4)

Error: Illegal car 2 in compound form (2 -2 4).
  1 (continue) Evaluate 2 and ignore the rest.
  2 (abort) Return to top loop level 0.

Type :b for backtrace or :c <option number> to proceed.
Type :bug-form "<subject>" for a bug report template or :? for other options.

CL-USER 10 : 1 > (atom 3)
T

CL-USER 11 : 1 > (atom 47)
T

CL-USER 12 : 1 > (atom '(/4 2))
NIL

CL-USER 13 : 1 > (atom (/ 4 2))
T

CL-USER 14 : 1 > (first (2 -2 4))

Error: Illegal car 2 in compound form (2 -2 4).
  1 (continue) Evaluate 2 and ignore the rest.
  2 (abort) Return to debug level 1.
  3 Evaluate 2 and ignore the rest.
  4 Return to top loop level 0.

Type :b for backtrace or :c <option number> to proceed.
Type :bug-form "<subject>" for a bug report template or :? for other options.

CL-USER 15 : 2 > first (2 -2 4)

Error: Illegal car 2 in compound form (2 -2 4).
  1 (continue) Evaluate 2 and ignore the rest.
  2 (abort) Return to debug level 2.
  3 Evaluate 2 and ignore the rest.
  4 Return to debug level 1.
  5 Evaluate 2 and ignore the rest.
  6 Return to top loop level 0.

Type :b for backtrace or :c <option number> to proceed.
Type :bug-form "<subject>" for a bug report template or :? for other options.

CL-USER 16 : 3 > (first '(2 -2 4))
2

CL-USER 17 : 3 > (first ((3) 4 5))

Error: Illegal car (3) in compound form ((3) 4 5).
  1 (continue) Evaluate (3) and ignore the rest.
  2 (abort) Return to debug level 3.
  3 Evaluate 2 and ignore the rest.
  4 Return to debug level 2.
  5 Evaluate 2 and ignore the rest.
  6 Return to debug level 1.
  7 Evaluate 2 and ignore the rest.
  8 Return to top loop level 0.

Type :b for backtrace or :c <option number> to proceed.
Type :bug-form "<subject>" for a bug report template or :? for other options.

CL-USER 18 : 4 > (first '(3) 4 5)

Error: The call (#<Function FIRST 4130092124> (3) 4 5) does not match definition (#<Function FIRST 4130092124> LIST).
   1 (continue) Return a value from the call to #<Function FIRST 4130092124>.
   2 Try calling #<Function FIRST 4130092124> again.
   3 Try calling another function instead of #<Function FIRST 4130092124> with the same arguments.
   4 Try calling #<Function FIRST 4130092124> with a new argument list.
   5 (abort) Return to debug level 4.
   6 Evaluate (3) and ignore the rest.
   7 Return to debug level 3.
   8 Evaluate 2 and ignore the rest.
   9 Return to debug level 2.
  10 Evaluate 2 and ignore the rest.
  11 Return to debug level 1.
  12 Evaluate 2 and ignore the rest.
  13 Return to top loop level 0.

Type :b for backtrace or :c <option number> to proceed.
Type :bug-form "<subject>" for a bug report template or :? for other options.
Error while reading: Unmatched right parenthesis.
Error while reading: Unmatched right parenthesis.

CL-USER 19 : 5 >( first '((3) 4 5))
(3)

CL-USER 20 : 5 > (first '(((3) 0 (4 5)) ()))
((3) 0 (4 5))

CL-USER 21 : 5 > (first '(nil))
NIL

CL-USER 22 : 5 > (listp '( 3 4))
T

CL-USER 23 : 5 > (listp 3)
NIL

CL-USER 24 : 5 > (car '(3 4 5 6))
3

CL-USER 25 : 5 > 