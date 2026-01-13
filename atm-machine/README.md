schemas

Acoount TABLE (id, userName, PIN(4), BalanceId, TransactionId, PaymentId) // for checking account and history

Balance TABLE (id, USD, KHR, AccountId) // for keeping and checking balance

Transaction TABLE (id, TransactionUSD, TransactionKHR, AccountId) // for keeping and checking transaction

Payment TABLE (id, PaymentUSD, PaymentKHR, AccountId) // for keeping and checking payment

Receipt TABLE (id, Action(Balance, Transaction Payment), TotalBalanceUSD, TotalBalanceKHR, AccountId) // for keeping and checking action of the users and printing the receipt for users if they want

first user login or create account

if login will check PIN then go to account to shows every options to users (Payment, Balance...etc.)
if successful created account will go to account to shows every options to users (Payment, Balance...etc.)