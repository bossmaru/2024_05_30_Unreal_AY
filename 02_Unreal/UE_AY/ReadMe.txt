24-07-22
- 언리얼 5
--> 게임 엔진들은 영화촬영에 비유할 수가 있다.
--> 세트장 : World
--> 배우 : Actor

- 언리얼은 상속구조와 컴포넌트 패턴이 핵심 철학.
--> 언리얼의 모든 오브젝트들은 UObject를 상속받아 만들어진다.
--> 앞에 U가 붙으면 UObject를 상속받았다는 컨벤션이다.
--> Actor만 제외 (AActor), 그리고 Actor를 상속받는 자식들은 앞에 A가 붙는다.
--> F가 붙으면 UObject를 상속받는 객체가 아니다.

UPROPERTY( ??? )


ConstructorHelpers
- 생성자에서 언리얼에디터에 존재(프로젝트 파일에 저장되어 있는)하는 정보들을 읽어올 수 있게 도와준다.


// 240725 과제
- ConstructHelper:: FindObject, FindClass 용도
- Local과 Local이 안붙은 수학 함수들의 차이
- 언리얼의 Cast
- 언리얼 액터의 수명 주기 (언제 생성되는지)

- Delegate
-- 1. Delegate 방법
-- 2. 클래스 객체로 직접 함수 호출
---- 단점
---- 클래스간의 결합도가 높아진다


// 240726 과제
1. 지금까지 한 작업들 본인 프로젝트로 새로 파서 다시 한번 만들기
sub : 현재 레벨에 Actor(Character형) 배치( C++로 해보길 추천)
 - 멤버변수에 hp, attackDamage 

- 동적할당
-- Actor-> SpawnActor
-- Component-> CreateDefaultSubObject

- 충돌
-- Block
-- Overlap
-- Ignore

// 240730 과제
1. 무기 획득 -> 사라짐,  attackDamage 증가
2. G누르면 획득한 아이템 버리기, attackDamage 감소
