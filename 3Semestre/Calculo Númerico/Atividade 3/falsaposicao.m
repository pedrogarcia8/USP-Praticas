% Método da falsa posição 
% Pedro Garcia 11846943
function x = falsaposicao(func, a, b, tol)
% [a,b]: intervalo com f(a)*f(b)<0
x = ((a * func(b)) - (b * func(a))) / (func(b) - func(a));
erro = inf;

while erro > tol
    if func(a)*func(x) < 0
        b = x;
    else
        a = x;
    end;
    
    x0 = x;
    x = ((a * func(b)) - (b * func(a))) / (func(b) - func(a));
    erro = abs(x-x0);
end;