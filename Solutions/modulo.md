<!-- Original Post on [quora.com][1].

[1]: https://www.quora.com/How-do-I-output-modulo-10-9-+-7-in-competitive-programming        "https://www.quora.com/How-do-I-output-modulo-10-9-+-7-in-competitive-programming" -->


Original Post <a href="https://www.quora.com/How-do-I-output-modulo-10-9-+-7-in-competitive-programming" target="_blank">Quora.com</a>
-----------------------------------------------------------
How do I output modulo 10^9 + 7 in competitive programming?
-----------------------------------------------------------

There are many questions that requires the answer with modulo 10^9+7, so that number does not overflow.

**Addition** :<br>
 (A+B)%mod = A%mod + B%mod  <br>
It still can Overflow, so take modulo of this also. <br>
 (A+B)%mod = (A%mod + B%mod)%mod

**Subtraction** :<br>
 (A-B)%mod = (A%mod + (-B)%mod)%mod <br>
 (A-B)%mod = (A%mod - B%mod + mod)%mod  <br>

**Multiplication** :<br>
 (A*B)%mod = (A%mod * B%mod)%mod

**Division** :<br>
Here comes a little problem to handle division modulo.<br>
**NOTE THAT** : (A/B)%mod is **not** equal to (A%mod / B%mod)%mod. <br>

(A/B)%mod = (A%mod * inv(B)%mod + mod)%mod, where inv(B) is inverse of B.<br>
Now, how to calculate inv(B)%mod.<br>
inv(B)%mod=B^-1 % mod=B^(mod-2)%mod,** only if B and mod are COPRIME**.<br>
If mod is prime(like, 10^9+7), then above formula will work.(Why ?)<br>
So, (A/B)%mod = (A*B^(mod-2))%mod, if B and mod are **COPRIME**.<br>

**Power** :<br>
(A^B)%mod=(A^(B%(mod-1)))%mod