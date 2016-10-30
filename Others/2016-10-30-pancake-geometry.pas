/*
	BZOJ 2472 Pancake
	梁健楠
*/
var
    N,i,j,ans:longint;
    a:array[0..110]of longint;
    x,y:array[0..110]of extended;

    function pd(x1,y1,x2,y2:extended):longint;
    var  tmp:extended;
    begin
        tmp:=x1*y2-x2*y1;// 叉积.
        if tmp<0 then exit(-1);
        if tmp>0 then exit(1);
        tmp:=x1*x2+y1*y2; //点积.
        if tmp<0 then exit(-1);
        if tmp>0 then exit(1);
    end;

    procedure work(px,py:extended);
    var  p,i,tmp:longint;
    begin
	// 选顶点p与点(px,py)作为直线,将顶点划分成两堆点集.
        for p:=1 to N do begin
            for i:=1 to N do a[i]:=pd(x[p]-px,y[p]-py,x[i]-px,y[i]-py);
            a[N+1]:=a[1];
            tmp:=0;
            for i:=1 to N do if a[i]*a[i+1]=-1 then inc(tmp);
            if tmp div 2+1>ans then ans:=tmp div 2+1;
        end;
    end;

begin
    while true do begin
        readln(N); if N=0 then break;
        for i:=1 to N do readln(x[i],y[i]);
        ans:=0;
	    // 枚举顶点对的中点作为中心点.
        for i:=1 to N do
        for j:=i+1 to N do work((x[i]+x[j])/2,(y[i]+y[j])/2);
        writeln(ans);
    end;
end.
