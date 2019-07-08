#include "strategy.h"
#include "game.h"
#define PI 3.14159265
Strategy::Strategy()
{

}

Player *Strategy::init_players()
{
    Player *players = new Player[5];
    /*
    Here you can set each of your player's name and your team formation.
    In case of setting wrong position, server will set default formation for your team.
     */

    players[0] = Player("SPARROW"  , Pos(-6.5,1.1) , 0);
    players[1] = Player("JOEE", Pos(-6.5,0)   , 1);
    players[2] = Player("SHERLOCK"  , Pos(-6.5,-1.1)  , 2);
    players[3] = Player("POTTER", Pos(-2.5,0)   , 3);
    players[4] = Player("DENERIS"  , Pos(-0.5,0)  , 4);


    return players;

}

Triple Strategy::do_turn(Game *game)
{
    Triple act;
    /*
    Write your code here
    At the end you have to set 3 parameter:
        player id -> act.setPlayerID()
        angle -> act.setAngle()
        power -> act.setPower()
     */

    //Sample code for shooting a random player in the ball direction with the maximum power:
    /*
    int your_player_Id = rand() % 5;
    act.setPlayerID(your_player_Id);
    double x1,y1;
    x1 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_x();
    y1 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_y();
    double x2,y2;
    x2 = game->get_ball()->get_Position().get_x();
    y2 = game->get_ball()->get_Position().get_y();
    */


    double x2,y2;
    double x1,y1;
    x2 = game->get_ball()->get_Position().get_x();
    y2 = game->get_ball()->get_Position().get_y();
    bool shotmos=false;
    bool shotdiv=false;
    bool shotdiv2= false;
    bool harifmos=true;
    bool harifdiv1=true;
    bool harifdiv2=true;
    bool harifmayel=true;
    bool khodiimos=true;
    bool khodiidiv1=true;
    bool khodiidiv2=true;
    bool khodiimayel=true;
    bool darvazemos=false;
    bool darvazediv1=false;
    bool darvazediv2=false;
    int divno;
    double ykhat;
    int jj=0;
    double xdivar2;
    int a[5];
    for(int i=0; i<5; i++)
    {
        a[i]=-1;
    }

    for(int i=0; i<5; i++)
    {
        double x4,y4;
        int your_player_Id = i;
        x4 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_x();
        y4 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_y();

        if(x4<x2)
        {
                double shib;
                shib=(y2-y4)/(x2-x4);
                for(int j=0; j<5; j++)
                {
                    double x3,y3;
                    x3 = game->get_oppTeam()->get_players()[j].get_pos().get_x();
                    y3 = game->get_oppTeam()->get_players()[j].get_pos().get_y();
                    ykhat=y4-shib*(x4-x3);
                    if(ykhat-1.001<=y3 && y3<=ykhat+1.001)
                    {
                        harifmos = false;
                        break;
                    }
                }
                for(int j=0; j<5; j++)
                {
                    if(j != i)
                    {
                        double x3,y3;
                        x3 = game->get_myTeam()->get_players()[j].get_pos().get_x();
                        y3 = game->get_myTeam()->get_players()[j].get_pos().get_y();
                        ykhat=y4-shib*(x4-x3);
                        if(ykhat-1.001<=y3 && y3<=ykhat+1.001)
                        {
                            khodiimos = false;
                            break;
                        }
                    }
                }
                ykhat=y4-shib*(x4-7);
                if(-1.13<=ykhat && ykhat<=1.13)
                {
                    darvazemos = true;
                }


            if(harifmos == true && khodiimos==true && darvazemos==true)
            {
                shotmos=true;
                a[jj]=i;
                jj++;
            }
        }

        }
        if(shotmos==true)
        {
            int maax_id;
            for(int i=0; i<5; i++)
            {
                if(a[i] != -1)
                {
                    double x3;
                    double maax=-100;

                    x3 = game->get_myTeam()->get_players()[i].get_pos().get_x();
                    if(x3>maax)
                    {
                        maax=x3;
                        maax_id=i;
                    }
                }
            }
            double xshotmos,yshotmos;
            xshotmos = game->get_myTeam()->get_players()[maax_id].get_pos().get_x();
            yshotmos = game->get_myTeam()->get_players()[maax_id].get_pos().get_y();
            x1=xshotmos;
            y1=yshotmos;
            act.setPlayerID(maax_id);
        }
    if(shotmos==false)
    {
                for(int i=0; i<5; i++)
                {
                    int your_player_Id = i;
                    double x4,y4;
                    double xtadivar;

                    x4 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_x();
                    y4 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_y();
                    if(x4<x2)
                    {
                    xtadivar=(7+x4)/2;

                    if(xtadivar>x2)
                    {
                        divno=-1;
                    }
                    else if(xtadivar<x2)
                    {
                        divno=1;
                    }
                    else
                        divno=0;

                    if(divno==-1)
                    {

                        double shib;
                        shib=(y2-y4)/(x2-x4);
                        shib=-shib;
                        double xdivar;
                        xdivar=x4-(y4+4)/shib;
                        for(int j=0; j<5; j++)
                        {
                            double x3,y3;
                            x3 = game->get_oppTeam()->get_players()[j].get_pos().get_x();
                            y3 = game->get_oppTeam()->get_players()[j].get_pos().get_y();
                            ykhat=-4-shib*(xdivar-x3);
                            if(ykhat-1.001<=y3 && y3<=ykhat+1.001)
                            {
                                harifdiv1 = false;
                                break;
                            }
                        }
                        for(int j=0; j<5; j++)
                        {
                            if(j != i)
                            {
                                double x3,y3;
                                x3 = game->get_myTeam()->get_players()[j].get_pos().get_x();
                                y3 = game->get_myTeam()->get_players()[j].get_pos().get_y();
                                ykhat=-4-shib*(xdivar-x3);
                                if(ykhat-1.001<=y3 && y3<=ykhat+1.001)
                                {
                                    khodiidiv1 = false;
                                    break;
                                }
                            }
                        }
                        ykhat=-4-shib*(xdivar-7);
                        if(-1.13<=ykhat && ykhat<=1.13)
                        {
                            darvazediv1 = true;
                        }
                        if(harifdiv1 == true && khodiidiv1==true && darvazediv1==true)
                        {
                            shotdiv=true;
                            a[jj]=i;
                            jj++;
                        }

                    }
                    }
                }
                if(shotdiv==true)
                {
                int maax_id2;
                for(int i=0; i<5; i++)
                {
                    if(a[i] != -1)
                    {
                        double x3;
                        double maax=-100;

                        x3 = game->get_myTeam()->get_players()[i].get_pos().get_x();
                        if(x3>maax)
                        {
                            maax=x3;
                            maax_id2=i;
                        }
                    }
                }
                double xshotdiv,yshotdiv;
                xshotdiv = game->get_myTeam()->get_players()[maax_id2].get_pos().get_x();
                yshotdiv = game->get_myTeam()->get_players()[maax_id2].get_pos().get_y();
                x1=xshotdiv;
                y1=yshotdiv;
                act.setPlayerID(maax_id2);
                }
                for(int i=0; i<5; i++)
                {
                    int your_player_Id = i;
                    double x4,y4;
                    double xtadivar;

                    x4 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_x();
                    y4 = game->get_myTeam()->get_players()[your_player_Id].get_pos().get_y();
                    if(x4<x2)
                    {
                    xtadivar=(7+x4)/2;

                    if(xtadivar>x2)
                    {
                        divno=-1;
                    }
                    else if(xtadivar<x2)
                    {
                        divno=1;
                    }
                    else
                        divno=0;



                    if(divno==1)
                    {



                        double xmid,ymid;
                        xmid=(x2+x4)/2;
                        ymid=(y2+y4)/2;
                        double shib2;
                        shib2=-1/((y2-y4)/(x2-x4));

                        xdivar2 = xmid-((ymid+4)/shib2);
                        double shib3;
                        shib3= y2+4/(x2-xdivar2);

                        for(int j=0; j<5; j++)
                        {
                            double x3,y3;
                            double ykhat3;
                            x3 = game->get_oppTeam()->get_players()[j].get_pos().get_x();
                            y3 = game->get_oppTeam()->get_players()[j].get_pos().get_y();
                            ykhat3=y2-shib3*(x2-x3);
                            if(ykhat3-1.001<=y3 && y3<=ykhat3+1.001)
                            {
                                harifdiv2 = false;
                                break;
                            }
                        }
                        for(int j=0; j<5; j++)
                        {
                            if(j != i)
                            {
                                double x3,y3;
                                double ykhat3;
                                x3 = game->get_myTeam()->get_players()[j].get_pos().get_x();
                                y3 = game->get_myTeam()->get_players()[j].get_pos().get_y();
                                ykhat3=y2-shib3*(x2-x3);
                                if(ykhat3-1.001<=y3 && y3<=ykhat3+1.001)
                                {
                                    khodiidiv2 = false;
                                    break;
                                }
                            }
                        }
                        double ykhat3;
                        ykhat3=-4-shib3*(xdivar2-7);
                        if(-1.13<=ykhat3 && ykhat3<=1.13)
                        {
                            darvazediv2 = true;
                        }
                        if(harifdiv2 == true && khodiidiv2==true && darvazediv2==true)
                        {
                            shotdiv2=true;
                            a[jj]=i;
                            jj++;
                        }
                    }
                    }
                    }
                if(shotdiv2==true)
                {
                int maax_id3;
                for(int i=0; i<5; i++)
                {
                    if(a[i] != -1)
                    {
                        double x3;
                        double maax=-100;

                        x3 = game->get_myTeam()->get_players()[i].get_pos().get_x();
                        if(x3>maax)
                        {
                            maax=x3;
                            maax_id3=i;
                        }
                    }
                }
                double xshotdiv2,yshotdiv2;
                xshotdiv2 = game->get_myTeam()->get_players()[maax_id3].get_pos().get_x();
                yshotdiv2 = game->get_myTeam()->get_players()[maax_id3].get_pos().get_y();
                x1=xshotdiv2;
                y1=yshotdiv2;
                x2=xdivar2;
                y2=0;
                act.setPlayerID(maax_id3);
                }





        if(shotdiv2 == false)
        {
            double xgoal,ygoal;
            double xt,yt;
            double shibmayel;

            double ykhatmayel;

            xgoal=7;

            if(y2<=0)
            {
            for(double i = 1.05 ; i>=-1.05; i-=0.21)
            {
                ygoal=i;
                shibmayel = (y2 - ygoal)/(x2 - xgoal);
                for(int j=0; j<5; j++)
                {
                    double x3,y3;
                    x3 = game->get_oppTeam()->get_players()[j].get_pos().get_x();
                    y3 = game->get_oppTeam()->get_players()[j].get_pos().get_y();
                    ykhatmayel=y2-shibmayel*(x2-x3);
                    if(ykhatmayel-1.001<=y3 && y3<=ykhatmayel+1.001)
                    {
                        harifmayel = false;
                        break;
                    }
                }
                for(int j=0; j<5; j++)
                {
                    if(j != i)
                    {
                        double x3,y3;
                        x3 = game->get_myTeam()->get_players()[j].get_pos().get_x();
                        y3 = game->get_myTeam()->get_players()[j].get_pos().get_y();
                        ykhatmayel=y2-shibmayel*(x2-x3);
                        if(ykhatmayel-1.001<=y3 && y3<=ykhatmayel+1.001)
                        {
                            khodiimayel = false;
                            break;
                        }
                    }
                }
                if(harifmayel == true && khodiimayel == true)
                {
                xt = x2 - sqrt(((0.75)*(0.75))/((shibmayel*shibmayel+1)));
                yt = y2 - shibmayel*(x2-xt);
                x2=xt;
                y2=yt;
                break;
                }
            }

            double miin=100;
            int miiin_id;
            for(int i=0; i<5; i++)
            {
                double x4,y4,fasele;
                x4 = game->get_myTeam()->get_players()[i].get_pos().get_x();
                y4 = game->get_myTeam()->get_players()[i].get_pos().get_y();
                if(x4<x2)
                {
                    fasele=sqrt((x4-x2)*(x4-x2)+(y4-y2)*(y4-y2));
                    if(fasele<miin)
                    {
                        miin=fasele;
                        miiin_id=i;
                    }



            double xshotran,yshotran;
            xshotran = game->get_myTeam()->get_players()[miiin_id].get_pos().get_x();
            yshotran = game->get_myTeam()->get_players()[miiin_id].get_pos().get_y();
            x1=xshotran;
            y1=yshotran;
            act.setPlayerID(miiin_id);
                }
            }
            }
            if(y2>0)
            {
            for(double i = -1.05 ; i<=1.05; i+=0.21)
            {
                ygoal=i;
                shibmayel = (y2 - ygoal)/(x2 - xgoal);
                for(int j=0; j<5; j++)
                {
                    double x3,y3;
                    x3 = game->get_oppTeam()->get_players()[j].get_pos().get_x();
                    y3 = game->get_oppTeam()->get_players()[j].get_pos().get_y();
                    ykhatmayel=y2-shibmayel*(x2-x3);
                    if(ykhatmayel-1.001<=y3 && y3<=ykhatmayel+1.001)
                    {
                        harifmayel = false;
                        break;
                    }
                }
                for(int j=0; j<5; j++)
                {
                    if(j != i)
                    {
                        double x3,y3;
                        x3 = game->get_myTeam()->get_players()[j].get_pos().get_x();
                        y3 = game->get_myTeam()->get_players()[j].get_pos().get_y();
                        ykhatmayel=y2-shibmayel*(x2-x3);
                        if(ykhatmayel-1.001<=y3 && y3<=ykhatmayel+1.001)
                        {
                            khodiimayel = false;
                            break;
                        }
                    }
                }
                if(harifmayel == true && khodiimayel == true)
                {
                xt = x2 - sqrt(((0.75)*(0.75))/((shibmayel*shibmayel+1)));
                yt = y2 - shibmayel*(x2-xt);
                x2=xt;
                y2=yt;
                break;
                }
            }

            double miin=100;
            int miiin_id;
            for(int i=0; i<5; i++)
            {
                double x4,y4,fasele;
                x4 = game->get_myTeam()->get_players()[i].get_pos().get_x();
                y4 = game->get_myTeam()->get_players()[i].get_pos().get_y();
                if(x4<x2)
                {
                    fasele=sqrt((x4-x2)*(x4-x2)+(y4-y2)*(y4-y2));
                    if(fasele<miin)
                    {
                        miin=fasele;
                        miiin_id=i;
                    }



            double xshotran,yshotran;
            xshotran = game->get_myTeam()->get_players()[miiin_id].get_pos().get_x();
            yshotran = game->get_myTeam()->get_players()[miiin_id].get_pos().get_y();
            x1=xshotran;
            y1=yshotran;
            act.setPlayerID(miiin_id);
                }
            }
            }

        }
    }




    double radian_angle = abs(atan((double)(y2-y1)/(double)(x2-x1)));//Calculate the angle from the chosen player to the ball
    int degree_angle = radian_angle * (180.0/PI) ;

    if(x2>x1)
    {
        if(y2<y1)
            degree_angle =360-degree_angle;
    }
    else
    {
        if(y2<y1)
            degree_angle += 180;
        else
            degree_angle = 180 - degree_angle;
    }
    act.setAngle(degree_angle);
    act.setPower(100);

    return act;


}

