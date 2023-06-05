# for the Shoshin Welyn competition thing
count = 1
ones = 0
threes = 0

def factorial(n):
    return n * factorial(n-1) if n > 0 else 1;

def get_mset_perms() -> int: 
    global ones, threes
    # always returns an int but doing floor divison anyways so print() removes the damn decimal __repr__()
    return factorial(ones+threes) // (factorial(ones) * factorial(threes))

def solution(num):
    global count, ones, threes
    if not solution.called:
        threes = num // 3
        solution.called = True;

    if num == 0 and solution.called:
        return
    elif num == 0 and not solution.called:
        count = 0
        return

    r = num % 3 # remainder

    if r == 0:
        res = get_mset_perms()
        ones += 3 
        threes -= 1
        count += res
        solution(num - 3)
    else:
        ones += r
        solution(num - r);

solution.called = False;


solution(4)
print(count)