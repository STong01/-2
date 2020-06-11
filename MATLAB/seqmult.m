function[h,nh]=seqmult(x,nx,y,ny)
nh=min(min(nx),min(ny)):max(max(nx),max(ny));
y1=zeros(1,length(nh));
y2=y1;
y1((nh>=min(nx))&(nh<=max(nx))==1)=x;
y2((nh>=min(ny))&(nh<=max(ny))==1)=y;
h=y1.*y2;