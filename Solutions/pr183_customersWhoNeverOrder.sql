SELECT Customers.name as Customers FROM Customers
left join Orders on  Orders.customerId = Customers.id
where Orders.id is null