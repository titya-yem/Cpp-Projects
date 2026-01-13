schemas

Acoount TABLE (id, userName, PIN(4))

Balance TABLE (id, USD, KHR, AccountId)

Transaction TABLE (id, TransactionUSD, TransactionKHR, AccountId)

Payment TABLE (id, PaymentUSD, PaymentKHR, AccountId)

Receipt TABLE (id, Action(Balance, Transaction Payment), TotalBalanceUSD, TotalBalanceKHR, AccountId)
