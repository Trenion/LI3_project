







SGV initSGV();
SGV destroySGV();
SGV loadSGVFromFiles(SGV sgv, char* filesFolderPath);
<?> getProductsStartedByLetter(SGV sgv, char letter);
<?> getProductSalesAndProfit(SGV sgv, char* productID, int month);
<?> getProductsNeverBought(SGV sgv, int branchID);
<?> getClientsOfAllBranches(SGV sgv);
<?> getClientsAndProductsNeverBoughtCount(SGV sgv);
<?> getProductsBoughtByClient(SGV sgv, char* clientID);
<?> getSalesAndProfit(SGV sgv, int minMonth, int maxMonth);
<?> getProductBuyers(SGV sgv, char* productID, int branch);
<?> getClientFavoriteProduct(SGV sgv, char* clientID, int branch);
<?> getTopSelledProducts(SGV sgv, int limit);
<?> getClientTopProfitProducts(SGV sgv, char* clientID, int limit);