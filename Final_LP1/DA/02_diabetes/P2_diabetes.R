#mydata <-read.csv(file = "C:\\Users\\prjlab\\Desktop\\LP1\\diabetes.csv", header = TRUE, sep=",")
mydata <-read.csv(file = "/home/prjlab/diabetes.csv", header = TRUE, sep=",")

View(mydata)

library(caTools)

library(e1071)

# Part-1 caTools
temp_field <- sample.split(mydata,SplitRatio=0.7)

#70% willbe in training
train <- subset(mydata, temp_field==TRUE)
# 30 % will be in testing

test <- subset(mydata, temp_field==FALSE)

# display few samples that are used for training & testing
head(train)
head(test)

# Part-2 e1071

# building naive Bayes

my_model <-naiveBayes(as.factor(train$Outcome)~.,train)

# To see summaries of the probabilities calculated
my_model


#predicting probabilities, type=class oy raw after the test data

pred1<-predict(my_model,test[,-9])
pred1
View(pred1)

pred1<-predict(my_model,test[,-9],type="class")
pred1


pred1<-predict(my_model,test[,-9],type="raw")
pred1


#generate the confusion matrix


pred1<-predict(my_model,test[,-9])
pred1
 
table(pred1,test$Outcome,dnn = c("predicted","Actual"))

# to save the prediction
output <- cbind(test,pred1)
View(output)












