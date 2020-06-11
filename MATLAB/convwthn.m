function[h,nh] = convwthn(x,nx,y,ny)
h = conv(x,y);
nh1 = nx(1)+ny(1);
nh2 = nx(end)+ny(end);
nh = [nh1:nh2];