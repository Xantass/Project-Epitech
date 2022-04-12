FROM maven:3.5-jdk-8-alpine AS builder
WORKDIR /path
COPY . .
RUN mvn dependency:resolve
COPY src/ .
RUN mvn package

FROM openjdk:8-jre-alpine
COPY --from=builder . .
WORKDIR /path/target
CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]