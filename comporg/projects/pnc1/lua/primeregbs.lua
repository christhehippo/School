

function prime(n)
 local root = math.sqrt(n)
 for i = 2,root,1
 do
   if (n % i) == 0 then
     return false
   end
   return true
 end
 end

 if prime(3) == true then
 	printf("3")
end

