function [sys] = syscal(o, s)
%==========================

%sys = [ o(:,1), o(:,2) - s(:,2)];
sys = [ o, s(:,2), s(:,2) - o(:,2), (s(:,2)./o(:,2) - 1)];
% x, y, ey, sy, sy-y, (sy/y -1)
% 1, 2,  3,  4,    5, 6
%==========================
end
