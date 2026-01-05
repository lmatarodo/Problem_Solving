import sys

st = []
temp = 1, answer = 0
s = input()

for i in range(len(s)):
    if s[i] == '(':
        temp *= 2
        st.append('(')
        
    elif s[i] == '[':
        temp *= 3
        st.append('[')
        
    elif s[i] == ')':
        if not st or st[-1] != '(':
            print(0)
            sys.exit(0)
        
        if s[i - 1] == '(':
            answer += temp
            temp //= 2
            st.pop()
            
        elif s[i - 1] != '(':
            temp //= 2
            st.pop()
            
    elif s[i] == ']':
        if not st or st[-1] != '[':
            print(0)
            sys.exit(0)
        
        if s[i - 1] == '[':
            answer += temp
            temp //= 3
            st.pop()
            
        elif s[i - 1] != '[':
            temp //= 3
            st.pop()
            
if st:
    print(0)
else:
    print(answer)