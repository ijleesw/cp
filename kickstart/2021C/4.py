import pprint

def getTree(expr):
    if expr[0] != '(':
        return {'type': 'int', 'value': int(expr)}

    sz = len(expr)
    paren_cnt = 0
    op = -1
    depth = 0
    for pos in range(1, sz - 1):
        if expr[pos] == '(':
            depth += 1
        elif expr[pos] == ')':
            depth -= 1
        elif depth == 0 and (expr[pos] == '+' or expr[pos] == '*' or expr[pos] == '#'):
            op = pos
            break

    return {'type': expr[op], 'left': getTree(expr[1:op]), 'right': getTree(expr[op + 1:sz - 1])}

# scala, left, right, count
def evaluate(tree):
    if tree['type'] == 'int':
        return tree['value'], None, None, 0

    ls, ll, lr, lc = evaluate(tree['left'])
    rs, rl, rr, rc = evaluate(tree['right'])

    if tree['type'] == '+':
        if ll is None and rl is None:
            return ls + rs, None, None, 0
        elif ll is not None:
            return ls + rs, ll, lr, lc
        elif rl is not None:
            return ls + rs, rl, rr, rc
        else:   # not considered in tc 1
            return ls + rs, ll, lr, lc + rc

    elif tree['type'] == '*':
        if ll is None and rl is None:
            return ls * rs, None, None, 0
        elif ll is not None:
            if rs == 0:
                return 0, None, None, 0
            else:
                return ls * rs, ll, lr, lc * rs
        elif rl is not None:
            if ls == 0:
                return 0, None, None, 0
            else:
                return ls * rs, rl, rr, ls * rc
        else:   # not considered in tc 1
            return ls * rs, ll, lr, lc * rc

    else:
        return 0, ls, rs, 1

def scalaComp(tree):
    if tree['type'] == 'int':
        return

    scalaComp(tree['left'])
    scalaComp(tree['right'])

    if tree['type'] == '+':
        if tree['left']['type'] == 'int' and tree['right']['type'] == 'int':
            tree['type'] = 'int'
            tree['value'] = tree['left']['value'] + tree['right']['value']
            del tree['left']
            del tree['right']
        elif tree['left']['type'] != 'int' and tree['right']['type'] == 'int':
            tree['left'], tree['right'] = tree['right'], tree['left']

    elif tree['type'] == '*':
        if tree['left']['type'] == 'int' and tree['right']['type'] == 'int':
            tree['type'] = 'int'
            tree['value'] = tree['left']['value'] * tree['right']['value']
            del tree['left']
            del tree['right']
        elif (tree['left']['type'] == 'int' and tree['left']['value'] == 0) or (tree['right']['type'] == 'int' and tree['right']['value'] == 0):
            tree['type'] = 'int'
            tree['value'] = 0
            del tree['left']
            del tree['right']

def solve(t):
    N = int(input())

    results = []

    for n in range(N):
        expr = input()
        if expr.count('#') == 1:
            tree = getTree(expr)
            results.append(evaluate(tree))
        else:
            tree = getTree(expr)
            scalaComp(tree)

#    pprint.PrettyPrinter().pprint(results)

    last = 0
    equiv = []
    for n in range(N):
        found = False;
        for prev in range(n):
            if results[n] == results[prev]:
                equiv.append(equiv[prev])
                found = True;
                break;

        if not found:
            last += 1
            equiv.append(last)

    print(f'Case #{t}: ', end='')
    for e in equiv:
        print(f'{e} ', end='')
    print('')

def main():
    T = int(input())
    for t in range(1, 1 + T):
        solve(t)

if __name__ == '__main__':
    main()
