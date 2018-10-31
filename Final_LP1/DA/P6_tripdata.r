
library(e1071)
library(rpart)
library(caTools)

mydata1 <-read.csv(file = "C:\\Users\\prjlab\\Desktop\\LP1\\201805-capitalbikeshare-tripdata.csv", header = TRUE, sep=",")
View(mydata1)

# cosiders column 1,4,6,9-output class

subset_mydata <- mydata1[,c(1,4,6,9)]
View(subset_mydata)
#split


temp_field <- sample.split(subset_mydata,SplitRatio=0.9)
train <- subset(subset_mydata, temp_field==TRUE)
test <- subset(subset_mydata, temp_field==FALSE)
summary(train)
summary(test)
head(train)
head(test)



fit <- rpart(train$Member.type~.,data=train,method="class")

# to display
#try other parameter : compress=true in plot
#cex=0.7 in next & so on
plot(fit)
text(fit)


#test data excluding the last column
pred <- predict(fit,newdata=test[,-4],type=("class"))
# .....after generating output 4th column is the last column

mean(pred==test$Member.type)

# display the output of test data
output <- cbind(test,pred)
View(output)



