function [h,nh] = seqfold(x,nx)
h = fliplr(x);
nh = -fliplr(nx);