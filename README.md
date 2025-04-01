[1인개발 콘솔 슛팅 게임 프로젝트]

작업 기간 : 2025.03.27(목) ~ 03.31(월) 약 5일
작업 시간 : 약 20시간
사용 언어 : C++ (문자열 처리는 c스타일, string 사용 x)


[활용 & 구현 기술]

 - 더블 퍼퍼링
 - 씬 전환
 - 충돌
 - Delta Time
 - Sound (DLL 활용)
 - 단일 연결리스트 (bullet, item종류에 활용/ enemy는 vector STL활용)


[후기]

 게임 엔진으로 쉽게 씬전환, 충돌, deltatime, 딜레이(코루틴...), audio system을 활용하다가 직접 구현해보니 진짜 개발을 하는 느낌이라 좋았고 게임 엔진에 대한 이해도가 더 높아졌다. 앞으로는 게임엔진의 기능을 활용할 때 그냥 쓰지 말고 내부 소스코드를 열어보는 습관을 들여야겠다고 생각했다.
 또 항상 라이브러리로 제공되는 자료구조를 활용하다가 처음으로 직접 구현한 단일연결리스트를 객체 관리에 활용하였는데, 그동안 자료구조를 단순 시험용으로 공부하다가 직접 활용해보니 자료구조의 필요성과 소중함을 더 느꼈다.

 아쉬운 점은 아무래도 콘솔게임이다보니 그래픽/ 연출이 부족했다는 점이다. 콘솔 게임으로 연출까지 구현하시는 분들은 정말 대단하신 것 같다. 또 단일연결리스트를 구현할 때 노드에 담을 데이터 타입이 여러가지 있었는데 템플릿이 기억이 잘 나지 않아서 조금 수동적인 방식을 선택한 부분이 아쉬웠다. (base타입의 클래스를 만들고 노드 데이터 타입을 base로 지정, base 상속받는 다양한 클래스를 만들어서 리스트에 업캐스팅 할당, 다운캐스팅을 통해 멤버 접근)
그래서 enemy는 list를 따로 만들지 않고 그냥 벡터 컨테이너를 사용했다..

 C++고급문법을 더 공부해서 효율적인 코드를 작성할 수 있도록 하고, 기초도 더 탄탄히 다져야겠다.


 [Screen Image]
 
![메뉴화면](https://github.com/user-attachments/assets/caee54fc-1cc6-43f0-b101-b4c549237fb4)
![인포화면](https://github.com/user-attachments/assets/9d9c16f2-7c31-46f6-91d0-a0b8cbd45061)
![플레이화면](https://github.com/user-attachments/assets/bf4d3ccc-da02-46a3-b0a2-10f86d5d8062)
![성공화면](https://github.com/user-attachments/assets/ed57a1ab-b55d-44a6-bcd8-4e32c2383615)
