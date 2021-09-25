## 🌞Chapter01 연습문제🌞_Yeram522

📘 C언어로 쉽게 풀어쓴 자료구조(p.36 - 37)

⭐ => 아리까리, 모르겠는 문제!

.

`[01]` **2개의 정수를 서로 교환하는 알고리즘**

```pseudocode
SET int a,b;
SET int temp;
INIT temp = a; a = b; b = temp;
```



`[02]` **입력받은 2개의 정수 중에서 더 큰 수를 찾는 알고리즘.**

```pseudocode
INPUT int a, b;
IF a > b THEN
  PRINT a;
IF a < b THEN
  PRINT b;
```



`[03]` **1 ~ n 까지의 합을 계산하는 알고리즘.**

```pseudocode
INPUT int N;
INIT int Sum = 0;
FOR int i = 1; i < N + 1 ;i++
  Sum+=i;
```



`[04]` **Set(집합) 추상 자료형 정의**

집합 = 서로 구분되는**(difference)** 값들의 순서 없는 무리.

```pseudocode
class Set
{
Creat():= Set 자료형 요소를 생성한다.
Check_Difference() =: 중복되는 원소를 제거한다. 
Insert(s):=집합에서 원소 s를 삽입한다.
Remove(s):=집합에서 원소 s를 제거한다.
Union(s1,s2):= 집합 s1,s2의 합집합을 반환한다.
intersection(s1,s2):=집합 s1,s2의 교집합을 반환한다.
Is_In(s):=원소가 집합 안에 존재하면 참, 아니면 거짓을 반환한다.
}
```

reference👀[link](https://travelbeeee.tistory.com/383)

`[05]` **Boolean 추상 자료형 정의**

```pseudocode
class Boolean
{
Creat():= bool 자료형 요소를 생성한다.
True(b):= bool 자료형을 참으로 초기화한다.
False(b):= bool 자료형을 거짓으로 초기화한다.
And(b1,b2):= bool 자료형 b1,b2가 모두 참이라면 참, 아니라면 거짓을 반환한다.
Or(b1,b2):= bool 자료형 b1,b2가 모두 거짓이라면 거짓, 아니라면 참을 반환한다.
Xor(b1,b2):= bool 자료형 b1,b2가 다르다면 참, 같다면 거짓을 반환한다.
Not(b):= bool 자료형 b가 참이라면 거짓, 거짓이라면 참을 반환한다.
}
```

reference👀

![이미지](https://user-images.githubusercontent.com/63442636/134760707-89012b50-e520-49c8-870d-45ef8453a8c8.png)

`[06]`
$$
O(n)
$$




⭐`[07]`

![이미지](https://user-images.githubusercontent.com/63442636/134759951-dfae2906-9014-420e-a7b8-a68f2a46dc7f.png)

```c
for(i = -; i < n; i++)// n번 수행
    for(j = 1; j<n; j*=2)// 2^k = n; k= log2; j -> log2 n번 수행
        printf("Hello");
```

$$
O(n*log_2n)
$$





`[08]`  **시간복잡도 함수를 빅오 표기법으로 나타내기.**
$$
시간복잡도 함수 : n^2+10n+8
$$

> <u>정답</u>

$$
(3)=O(n^2)
$$



`[09] `**시간복잡도 함수가 나타내는 것 **

> (1) 연산의 횟수



`[10]` **입력개수가 2배로 되었을 때 실행시간의 증가 추세는?**

> (1) 변함없다.

$$
O(n^2)=O((2n)^2)=O(4n^2)
$$



`[11]` **f(n)에 대하여 <u>엄격한 상한</u>을 제공하는 표기법.**

> (2) 빅오



`[12]` **빅오표기법들을 수행시간이 적게 걸리는 것부터 나열**

> $$
> O(1)<O(logn)<O(n)<log(nlogn)<O(2^n)<O(n^2)<O(n!)
> $$

<img src="https://user-images.githubusercontent.com/63442636/134760741-3de6a6ff-f082-4e78-8754-f879befe9d70.png" width="600" height="300"/>



`[13]` 언제 f(n)이 g(n)보다 작은 값을 갖는지 구하라.
$$
f(n) = 30n+4,g(n)=n^2
$$
<img src="https://user-images.githubusercontent.com/63442636/134760803-8e42a09c-a219-423d-8eb0-068dc38ed252.png" width="300" height="300"/>

> n=4 일때



`[14]`

>O(n)
>
>O(2n) -> O(n)
>
>O(3n+1) -> O(n)
>
>O(4n-1) -> O(n)

$$
O((log_2n-3)(log_2n-2)^4)
$$

> ⭐O((log_2 n)^5)



`[15]` **빅오 표기법의 정의를 사용하여 다음을 증명하라.**
$$
5n^2 + 3 = O(n^2)
$$
<img src="https://user-images.githubusercontent.com/63442636/134763272-49566fb3-7f1d-4506-9af4-edb961f2d3d8.png" width="600" height="250"/>



`[16]` **빅오 표기법의 정의를 이용하여 아래의 식이 성립하지 않음을 보여라.**
$$
O(n) = 6n^2 + 3n
$$
<img src="https://user-images.githubusercontent.com/63442636/134763389-4bbf38b7-43b9-442b-b156-6693a53cf822.png" width="450" height="130"/>





`[17]` ⭐**다음 작업의 최악, 최선의 시간복잡도를 빅오 표기법으로 말하라.**

> (1) 배열의 n번째 숫자를 화면에 출력한다.
>
> - 최선 : O(n)
> - 최악 : O(n)
>
> (2) 배열안의 숫자 중에서 최소값을 찾는다.
>
> - 최선 : O(1)
> - 최악 : O(n)
>
> (3) 배열의 모든 숫자를 더한다.
>
> - 최선: O(n)
> - 최악: O(n)

