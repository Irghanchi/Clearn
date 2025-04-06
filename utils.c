#ifndef utils_h
#define utils_h

double dis(Vector2 a , Vector2 b){
        double lx,ly,dist;
        lx = b.x -a.x;
        ly = b.y - a.y;
        dist = sqrt(pow(lx,2)+pow(ly,2));
        return dist;                                    }
double  TArea(Vector2 a,Vector2 b,Vector2 c){
        double cross;                              
        Vector2 ab = { b.x - a.x , b.y - a.y};
        Vector2 ac = { c.x - a.x , c.y - a.y};
        cross = ab.x * ac.y - ab.y*ac.x;
        return fabs(cross)/2;
}
double m(Vector2 a, Vector2 b){
        return (a.y -b.y)/(a.x -b.x);
}
double c(Vector2 a, double m){
        return a.y - m*a.x;
}
bool IsCollide(Vector2 cirpose, double radius,Vector2 p1,Vector2 p2){
  double mind = (2* TArea(cirpose ,p1,p2)/dis(p1,p2));
  if (mind <= radius){
    return true;
  }else{
    return false;
  }
}
Vector2 mind(Vector2 cirpose,Vector2 a,Vector2 b){
  double da,db;
  da = dis(cirpose,a);
  db = dis(cirpose,b);
  if (da > db){
    return b;
  }else{
    return a;
  }
}


typedef struct{
        bool cond;
        Vector2 a;
        Vector2 b;
}intern;
intern intersec(Vector2 ball , double r , double m, double c){
        double A,B,C,disc;
        A = 1 + pow(m,2);
        B = 2* (m * (c - ball.y )- ball.x);
        C = pow(ball.x,2) +pow( (c - ball.y),2) - pow(r,2);
        disc = pow(B,2)-4 *A*C;
        Vector2 a;
        Vector2 b;
        bool cond;
        if (disc < 0){
                Vector2 a = {0.0,0.0};
                Vector2 b = {0.0,0.0};
                bool cond = false;
                intern res = { cond, a,b};
                return res;
        }else if (disc == 0){
                a.x = -B /(2*A);
                a.y = m*a.x + c;
                cond = true;
                Vector2 b = {0,0};
                intern res = { cond, a,b};
                return res;
        }else{
                double sqrtdisc;
                sqrtdisc = sqrt(disc);
                a.x = (-B + sqrtdisc)/ (2*A);
                b.x = (-B - sqrtdisc)/ (2*A);
                a.y = (m* a.x + c);
                b.y = (m* b.x + c);
                intern res = {true,a ,b};
                return res;
        }
}
#endif

