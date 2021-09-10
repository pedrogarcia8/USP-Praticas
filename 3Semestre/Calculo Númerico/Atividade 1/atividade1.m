% Pedro Garcia 11846943

n = input('');
for i = 1:n
    for j = 1 : i - 1
        A(i, j) = input('');
        A(j, i) = A(i, j);
    end
    
    A(i, i) = input('');
end

for i = 1 : n
    b(i, 1) = input('');
end

L = zeros(n, n);
for i = 1 : n
    L(i, i) = 1;
end

D = zeros(n, 1);
for i = 1 : n
    D(i) = A(i, i) - L(i, 1 : i - 1).^2 * D(1 : i - 1);
    for j = i + 1 : n
        L(j, i) = (A (j, i) - L(j, 1 : i - 1) .* L(i, 1 : i - 1) * D(1 : i - 1)) / D(i);
    end
end

z = zeros(n, 1);
y = zeros(n, 1);
x = zeros(n, 1);

y(1) = b(1);
for i = 2 : n
    y(i) = b(i) - L(i, 1 : i - 1) * y(1 : i - 1);
end

for i = 1 : n
    z(i) = y(i) / D(i);
end

x(n) = z(n);
for i = n - 1 : - 1 : 1
    x(i) = z(i) - L(i + 1 : n, i)' * x(i + 1 : n);
end

for i = 1 : n
    for j = 1 : i
        fprintf('%.6f\n', L(i, j));
    end
end

for i = 1 : n
    fprintf('%.6f\n', D(i, 1));
end

for i = 1 : n
    fprintf('%.6f\n', x(i));
end