import express from "express";
import dotenv from "dotenv";

dotenv.config();

const app = express();
app.use(express.json());

app.use("/", (req, res) => {
    res.send("Hello Lamdouy");
});

const port = process.env.PORT || 4000
app.listen(port, () => {
    console.log(`Server is running on port http://localhost:${port}`);
});