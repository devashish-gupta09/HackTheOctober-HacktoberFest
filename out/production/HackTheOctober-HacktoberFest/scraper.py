import twint
import nest_asyncio
import pandas as pd
nest_asyncio.apply()
# Configure
c = twint.Config()
c.Lang = "en"
c.Search = "taliban","afghanistan","Islam"
#,"dead"
c.Store_object = True
c.Store_csv = True
c.Limit=10000
c.Since = "2021-07-28"
c.Until = "2021-08-18" 
c.Output = "TAI.csv"
# Run
twint.run.Search(c)
# tweet_df = twint_to_pd(["date" , "username" , "tweet"])
data = pd.read_csv("TAI.csv")
print(data.columns)
tweet_df = data[["date" , "username" , "tweet"]]
# name1=name+1.csv
print(tweet_df)
tweet_df.to_csv("TAI2.csv")