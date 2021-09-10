% Entrada:
% n  - dimensao da matriz A e do sistema linear Ax=b
% d0 - entradas da diagonal principal da matriz SPD tridiagonal
% d1 - entradas da diagonal inferior (e superior ja que simetrica)
% b  - vetor lado-direito do sistema Ax=b

n = input('');

for i = 1:n
    d0(i, 1) = input('');
end

for i = 1:n-1
    d1(i, 1) = input('');
end

for i = 1:n
    b(i, 1) = input('');
end

ds = zeros(n, 1); % Diagonal acima da principal
for i = 1:(n - 1)
    ds(i,1) = d1(i,1);
end 

di = zeros(n, 1); % Diagonal abaixo da principal
for i = 2:n 
    di(i,1) = d1(i - 1, 1);
end

ds(1,1) = d1(1,1) / d0(1,1);

for i = 2:n
    ds(i,1) = ds(i,1) / (d0(i,1) - di(i,1) * ds(i-1,1));
end

b(1,1) =  b(1,1) / d0(1,1);

for i = 2:n
    b(i,1) = (b(i,1) - b(i-1,1) * di(i,1)) / (d0(i,1) - di(i,1) * ds(i-1,1));
end

x = zeros(n,1);
x(n,1) = b(n,1);

for i = (n-1):-1:1
   x(i,1) = b(i,1) - ds(i,1) * x(i+1,1);
end

for i = 1:n
    fprintf('%.6f\n', x(i,1));
end