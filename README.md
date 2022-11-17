# cub3d
[subject](https://github.com/tozggg/cub3d/blob/master/subject.pdf)  
MiniLibX 라이브러리를 이용해서 3d 게임 만들기 (with [@Jeongwoo04](https://github.com/Jeongwoo04))  
(레이트레이싱)  
<br>
<img width="50%" src="https://github.com/tozggg/cub3d/blob/master/cub3d_screen.gif?raw=true"/>
<br>
<br>
## Details
### 서브젝트 항목

```jsx
* 허용함수
ㄴ open close read write printf malloc free perror strerror exit
ㄴ math 라이브러리
ㄴ mlx 라이브러리 (! 어느버전으로?)

* Makefile - all clean fclean re bonus(! _bonus 조심)
* 맵파일은 .cub 확장자

* 최소화, 닫기 원활
* 벽이미지 선택가능(동서남북)
* 천장, 바닥 RGB로 선택

// 입력
화살표 왼쪽, 오른쪽 -> 시점전환
WASD -> 해당방향이동
esc , 빨간x버튼 -> 창 닫기

// 맵
NO SO WE EA -> 4방향 벽 이미지파일
F C -> 천장 바닥 RGB
맵 ㄱ
0 -> 빈공간
1 -> 벽
N S E W -> 플레이어 시작 위치(방향)
* 맵은 벽으로 둘러쌓여 있어야함
* 이미지파일-RGB-맵을 empty line(+1)으로 구분
* 맵을 제외하고는 순서 상관x

// Bonus
벽 충돌
미니맵
여닫이문(x)
스프라이트(x)
마우스로 시점 변경(x)

```

### DDA 알고리즘

- game 구조체

  posX posY → 현재 플레이어 위치

  dirX dirY → 보는 방향 방향벡터

  planeX planeY → 시야각 벡터

- dda 구조체

  cameraX → -1 ~ 1 화면상 위치

  raydirX raydirY → 광선의 방향벡터

  sideDistX sideDistY → 가장 처음만나는 면 벡터

  deltaDistX deltaDistY → 다음 만나는 면 벡터

  perp_wall_dist → 광선의 이동거리

  mapX mapY → 광선의 위치(int값)

  stepX stepY → 광선의 방향에따라 -1, 1

  hit → 벽에 부딪쳤으면 1

  side → hit시 어느방향 벽인가?

  lineHeight → 화면상 그려야하는 벽의 길이

  drawStart drawEnd → 화면의 수직선에 그릴 시작지점, 끝지점

  wallX → 부딪힌 벽의 0~1 비율

  texX texY → 뿌릴 텍스처 x, y 좌표

  step 

  texPos

  color → 버퍼에 덮을 텍스처의 픽셀 rgb

---

### 참고
[https://github.com/365kim/raycasting_tutorial](https://github.com/365kim/raycasting_tutorial)  
[https://github.com/sungyongcho/ii2r](https://github.com/sungyongcho/ii2r)
