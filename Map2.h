#pragma once
#include <iostream>
#include <Windows.h>

using namespace std;

//закрытый класс, дружественный только к снейк
class Map2
{
	
	char map[44][173] =
	{
	"===========================================================================================================================================================================#",
	"#                                                                                                                                                                          #",
	"#                                                                                   |-----------------------|                                                              #",
	"#                                                                                   |                       |                 ^                                            #",
	"#                                                                                   |                       |                 ^                                            #",
	"#                                                                                   |                       |                 ^                                            #",
	"#                            s sssss                T T T T T T T T T T             |                       |                 ^          ^                                 #",
	"#                            s                      T        T        T             |                       |                 ^          ^                                 #",
	"#                            s                      T        T        T             |                       |                 ^          ^                                 #",
	"#                            s                      T        T        T                                                       ^^^^^^^^^^^^                                 #",
	"#                            s                               T                                                                                                             #",
	"#                            s                               T                                                                                                             #",
	"#                            sssssss                         T                                                                                                             #",
	"#                            s                               T                                                                                                             #",
	"#                            s                               T                                                                                                             #",
	"#                            s                               T                                   !!!!!!!!!!!!!!!!!!           + + + + + + + + + +                          #",
	"#                            s                               T                                   $                +           +                 -                     |    #",
	"#                            s                               T                                   $                +           +                 -                     |    #",
	"#                                                                                                $                +           +                 -                     |    #",
	"#                                                                                                $                +           +                 -                     |    #",
	"#                                                                                                $                +           +                 -                     |    #",
	"#            M               M     V                 V                                           $                &&&&&&&&&&&&&                 -                     |    #",
	"#            M M           M M      V               V                                            $                &&&&&&&&&&&&&                 -                     |    #",
	"#            M  M         M  M       V             V                                                                                             -                    |    #",
	"#            M   M       M   M        V           V                                                                                              -                    |    #",
	"#            M    M     M    M         V         V                                                                                                +                   /    #",
	"#            M     M M M     M          V       V                                                                                                  +                 /     #",
	"#            M               M           V     V                                                                                                    +               /      #",
	"#            M               M            V   V                                                                                                      +             /       #",
	"#            M               M             V V                                                                                                        +___________/        #",
	"#                                                                                                                                                                          #",
	"#                                                                        %                                  ---                                                            #",
	"#                         ~~~~~~~~~~~~~~~~~~                      ~~~~~~~~~~~~~~                               %                                                           #",
	"#                        (                  ~                   ~                                               %                                 %                        #",
	"#                       (                    ~                ~                                                  %                                %                        #",
	"#                      (                      ~ ~ ~ ~ ~ ~ ~ ~                                                     %                              %                         #",
	"#                     (                                      %                           %                         %    % % % % %               %                          #",
	"#                    (                                        %                         %                           %   %         %            %                           #",
	"#                   (                                          %                       %                             % %            % %  % %  %                            #",
	"#                  (                                            %                     %                                                                                    #",
	"#                                                                % % % % % % % % % %                                                                                       #",                
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"============================================================================================================================================================================",
	};
	char map2[44][173] =
	{
	"===========================================================================================================================================================================#",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                      S S S S  S S       N  N  N  N                           N       N                     A                     K                 K     E E E E E       #",
	"#                      S          S       N        N   N                       N       N                    A A                    K               K       E       E       #",
	"#                      S          S       N        N    N                      N       N                   A   A                   K             K         E               #",
	"#                      S          S       N        N     N                     N       N                  A     A                  K           K           E               #",
	"#                      S                  N        N      N                    N       N                 A       A                 K         K             E               #",
	"#                      S                  N        N       N                   N       N                A         A                K       K               E               #",
	"#                      S                  N        N        N                  N       N               A           A               K     K                 E               #",
	"#                        S                N        N         N                 N       N              A             A              K   K                   E               #",
	"#                          S              N        N          N                N       N             A               A             K K                     E E E E E       #",
	"#                            S            N        N           N               N       N            A                 A            K   K                   E               #",
	"#                              S          N        N            N              N       N           A                   A           K     K                 E               #",
	"#                                S        N        N             N             N       N          A     A     A    A    A          K       K               E               #",
	"#                                  S      N        N              N            N       N         A                       A         K         K             E               #",
	"#                      S           S      N        N               N           N       N        A                         A        K           K           E               #",
	"#                      S           S      N        N                N          N       N       A                           A       K             K         E       E       #",
	"#                      S S S S S S S      N        N                 N N N N N N N N N N      A                             A      K               K       E E E E E       #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                      &&&&&&&                      &&&&&&&      GGGGGGGGGGGGG        E ~ ~ ~ ~ ~ ~       $                          % ^ ^ ^ ^ ^        ------------       #",
	"#                             &                    &             G           G        E           ~       $   &                      %         ?        +           +      #",
	"#                              &                  &              G           G        E           ~       $    &                     %         /        +           +      #",
	"#                               &                &               G           G        E           ~       $     &                    %         ?        +           +      #",
	"#                                &              &                G       G G G        E                   $      &                   %         ?        +           +      #",
	"#                                 &            &                 G                    E                   $       &                  %         ?        +           +      #",
	"#                                  &          &                  G                    E                   $        &                 %         ?        +           +      #",
	"#                                   &        &                   G                    E                   &         &                %         ?        +           +      #",
	"#                                   & & & & &                    G                    E                   &          &               %         ?        +           +      #",
	"#                                  &          &                  G                    E % % % % %         &           &              %         ?        +           +      #",
	"#                                 &            &                 G                    E                   &            &             %         ?          +        +       #",
	"#                                &              &                G       G G G        E                   &             &            %         ?            +     +        #",
	"#                               &                &               G           G        E                   &              &           %         ?              +++          #",
	"#                              &                  &              G           G        E           E       &               &          %         ?              +++          #",
	"#                             &                    &             G           G        E           E       &                &         %         ?                           #",
	"#                            &                      &            G           G        E           E       &                 &        %         ?                           #",
	"#                     &&&&&&&                        &&&&&&      G G G G G G G        E ~ ~ ~ ~ ~ ~       &                  & * * * *         ?                           #",
	"#                                                                                                                                                                          #",	
	"#                                                                                                                                                                          #",
	"============================================================================================================================================================================",
	};
	char map3[44][173] =
	{
	"===========================================================================================================================================================================#",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                          $     $ $                 $       $           E E E E E E E E E        A  A                                            p p p p p p p p p        #",
	"#                          $       $                 $       $           E               E        A   A                                           p               p        #",
	"#                          $       $                 $       $           E               E        A    A                                          p               p        #",
	"#                          $       $                 $       $           E               E        A     A                                         p               p        #",
	"#                          $       $                 $       $           E               E        A      A                                        p               p        #",
	"#                          $       $                 $       $           E                        A       A                                       p               p        #",
	"#                          $       $                 $       $           E                        A        A                                      p               p        #",
	"#                          $       $                 $       $           E                        A         A                                     p               p        #",
	"#                          $       $                 $       $           E                        A          A                                    p               p        #",
	"#                          $       $                 $       $           E                        A           A                                   p               p        #",
	"#                          $       $                 $       $           E             E          A            A                                  p               p        #",
	"#                          $       $                 $       $           E             E          A             A                                 p               p        #",
	"#                          $       $                 $       $           E             E          A              A                                p               p        #",
	"#                          $       $ $ $ $ $ $ $ $ $ $       $           E E E E E E E E          A               A                               p               p        #",
	"#                          $                                 $           E             E          A                A                              p               p        #",
	"#                          $                                 $           E             E          A                 A                             p               p        #",
	"#                          $                                 $           E                        A                  A                            p               p        #",
	"#                          $                                 $           E                        A                   A                           p               p        #",
	"#                          $                                 $           E                        A                    A                          p               p        #",
	"#                          $                                 $           E                        A                     A                         p               p        #",
	"#                          $                                 $           E                        A                      A                        p               p        #",
	"#                          $       $ $ $ $ $ $ $ $ $ $       $           E                        A  A   A    A   A   A   A                       p      p  p  p  p        #",
	"#                          $       $                 $       $           E                        A                        A                      p                        #",
	"#                          $       $                 $       $           E                        A                         A                     p                        #",
	"#                          $       $                 $       $           E                        A                          A                    p                        #",
	"#                          $       $                 $       $           E                        A                           A                   p                        #",
	"#                          $       $                 $       $           E                        A                            A                  p                        #",
	"#                          $       $                 $       $           E                        A                             A                 p                        #",
	"#                          $       $                 $       $           E                        A                              A                p                        #",
	"#                          $       $                 $       $           E                        A                               A               p                        #",
	"#                          $       $                 $       $           E             E          A                                A              p                        #",
	"#                          $       $                 $       $           E             E          A                                 A             p                        #",
	"#                          $       $                 $       $           E             E          A                                  A            p                        #",
	"#                          $       $                 $       $           E             E          A                                   A           p                        #",
	"#                          $ $ $ $ $                 $ $     $           E E E E E E E E          A                                    A          p                        #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"#                                                                                                                                                                          #",
	"============================================================================================================================================================================",
	};
	char apple;
	int applex;
	int appley;
	int time_resp_apple;
	int current_map;
	int get_current_ticks;
	/////////////////////////////////////////////////////////////////////////////////////////////
	void SetRespTime(int n);
	int GetRespTime() const;

	void SetApple(char symv);
	char GetApple() const;

	void ShowMap(int index) const;
	char GetCurrentChar(int index, int index2, int current_map);


	void SetMap(int number);
	int GetMap() const;

	void ChangeMap(int number);
	void ShowAplleOnMap();
	void GotoXY(int x, int y);
	void SetColor(int text, int background);
	Map2& operator = (const  Map2& src);
	friend ostream& operator << (ostream& os, const Map2& src);
	Map2(const Map2& src);
	Map2(int time_resp_apple = 220, char apple = '@', int map = 1);
	friend class Snake;
	friend class Menu;
};

