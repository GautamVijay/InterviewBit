https://www.quora.com/How-do-I-output-modulo-10-9-+-7-in-competitive-programming
-----------------------------------------------------------
How do I output modulo 10^9 + 7 in competitive programming?
-----------------------------------------------------------

There are many questions that requires the answer with modulo 10^9+7, so that number does not overflow.

Addition :
 (A+B)%mod = A%mod + B%mod
It still can Overflow, so take modulo of this also.
 (A+B)%mod = (A%mod + B%mod)%mod

Subtraction :
 (A-B)%mod = (A%mod + (-B)%mod)%mod
 (A-B)%mod = (A%mod - B%mod + mod)%mod

Multiplication :
 (A*B)%mod = (A%mod * B%mod)%mod

Division :
Here comes a little problem to handle division modulo.
NOTE THAT : (A/B)%mod is not equal to (A%mod / B%mod)%mod.

(A/B)%mod = (A%mod * inv(B)%mod + mod)%mod, where inv(B) is inverse of B.
Now, how to calculate inv(B)%mod.
inv(B)%mod=B^-1 % mod=B^(mod-2)%mod, only if B and mod are COPRIME.
If mod is prime(like, 10^9+7), then above formula will work.(Why ?)
So, (A/B)%mod = (A*B^(mod-2))%mod, if B and mod are COPRIME.
Power :
(A^B)%mod=(A^(B%(mod-1)))%mod