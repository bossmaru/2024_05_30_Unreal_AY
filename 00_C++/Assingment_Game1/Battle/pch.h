#pragma once


#include <iostream>
#include <vector>

using namespace std;

// 미리 컴파일된 헤더
// pch.h / pch.cpp 생성
// pch.cpp #include "pch.h"
// pch.cpp 속성 -> 미리컴파일된 헤더 만들기 / pch.h
// 프로젝트 속성 -> 미리컴파일된 헤더 사용 / pch.h

// 폴더화시켰을 때
// 프로젝트 속성 -> VC++디렉토리 -> 포함디렉토리 편집 -> $(ProjectDir) 적용

#include "Constants.h"

#include "Contents/Creature/Creature.h"
#include "Contents/Creature/Player.h"
#include "Contents/Creature/Monster.h"

#include "Contents/Creature/Knight.h"
#include "Contents/Creature/Archer.h"
#include "Contents/Creature/Mage.h"

#include "Contents/Creature/Goblin.h"

#include "Contents/World/World.h"