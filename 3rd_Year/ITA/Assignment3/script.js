
const rows = 50
const cols = 50

var tileWidth, tileHeight;
//Create canvas with the device resolution.

var isGameRunning = false;
var isGameOver = false;

var defaultSnakePos = [
    { x: 26, y: 24 },
    { x: 25, y: 24 },
    { x: 24, y: 24 },
    { x: 23, y: 24 },
    { x: 22, y: 24 }
];
var snake = [...defaultSnakePos];
var cross = [
    { x: 24, y: 24 },
    { x: 24, y: 25 },
    { x: 24, y: 23 },
    { x: 25, y: 24 },
    { x: 23, y: 24 },
];


var crossThreshold = 100;
var snakeColor = '#e25ca3';
var strokeColor = '#8e0441';
var foodColor = '#04bbfb';
var foodStroke = '#0489e7';
var crossColor = 'red';
var crossStroke = 'black';
var score = 0;
var food;

var direction = 1; // 0 - left, 1 - right, 2 - top, 3 - bottom

var audio = new Audio()

var PIXEL_RATIO = (function () {
    var ctx = document.createElement("canvas").getContext("2d"),
        dpr = window.devicePixelRatio || 1,
        bsr = ctx.webkitBackingStorePixelRatio ||
            ctx.mozBackingStorePixelRatio ||
            ctx.msBackingStorePixelRatio ||
            ctx.oBackingStorePixelRatio ||
            ctx.backingStorePixelRatio || 1;

    return dpr / bsr;
})();
createHiDPICanvas = function (ratio) {
    if (!ratio) { ratio = PIXEL_RATIO; }
    var can = document.getElementById("gameBoard");
    var w = Math.round($("#gameCanvasContainer").width() * 0.70);
    var h = Math.round((3 * w) / 4);
    can.width = w * ratio;
    can.height = h * ratio;
    can.style.width = w + "px";
    can.style.height = h + "px";
    tileWidth = Math.round(can.width / cols);
    tileHeight = Math.round(can.height / rows);
    return can;
}

var gameBoard = createHiDPICanvas();
const startButton = document.getElementById("startButton");

const gameBoardContext = gameBoard.getContext("2d");

const changeButtonAppearence = function () {
    if (isGameRunning) {
        $("#startButtonDiv").removeClass("startButton");
        $("#startButtonDiv").addClass("stopButton");
        $("#startButton").html("STOP");
    } else {
        $("#startButtonDiv").removeClass("stopButton");
        $("#startButtonDiv").addClass("startButton");
        $("#startButton").html("START");
    }
}

const checkSnakeCollision = function (newHead) {
    for (var i = 0; i < snake.length; i++) {
        if (newHead.x == snake[i].x && newHead.y == snake[i].y)
            return true;
    }
    return false;
}
const checkCrossCollision = function (newHead) {
    if (score < crossThreshold) return false;
    for (var i = 0; i < cross.length; i++) {
        if (newHead.x == cross[i].x && newHead.y == cross[i].y)
            return true;
    }
    return false;
}

const moveSnake = function () {
    var newHead;
    if (direction === 0) {
        newHead = { x: (snake[0].x - 1 + cols) % cols, y: snake[0].y };
    } else if (direction === 1) {
        newHead = { x: (snake[0].x + 1) % cols, y: snake[0].y };
    } else if (direction === 2) {
        newHead = { x: snake[0].x, y: (snake[0].y - 1 + rows) % rows };
    } else if (direction === 3) {
        newHead = { x: snake[0].x, y: (snake[0].y + 1 + rows) % rows };
    }

    if (newHead.x == food.x && newHead.y == food.y) {
        snake.unshift(newHead);
        generateFood();
        score += 10;
        renderScore();

    } else {
        if (checkSnakeCollision(newHead) || checkCrossCollision(newHead)) {
            isGameOver = true;
            isGameRunning = false;
            changeButtonAppearence();
        }
        snake.unshift(newHead);
        snake.pop();
    }
}

var toggler = 0;
const gameRunner = async function () {
    if (isGameRunning) {
        setTimeout(() => {
            renderRunner();
            gameRunner();
        }, 60)
    }
    else if (isGameOver) {
        setTimeout(() => {
            renderGameOver();
            gameRunner();
        }, 60);
    }

}

const renderGameOver = function () {
    clearScreen();
    if (toggler <= 4) {
        renderSnake();
        renderGameOverText();
    }
    if (score >= crossThreshold) renderCross();
    toggler = (toggler + 1) % 10;
}

const renderRunner = function () {
    moveSnake();
    clearScreen();
    renderSnake();
    renderFood();
    if (score >= crossThreshold) renderCross();

}

const generateFood = function () {
    food = { x: Math.round(Math.random() * 49), y: Math.round(Math.random() * 49) }
}

const renderFood = function () {
    gameBoardContext.fillStyle = foodColor;
    gameBoardContext.strokeStyle = foodStroke;
    gameBoardContext.fillRect(food.x * tileWidth, food.y * tileHeight, tileWidth, tileHeight);
    gameBoardContext.strokeRect(food.x * tileWidth, food.y * tileHeight, tileWidth, tileHeight);

}

const renderCross = function () {
    gameBoardContext.fillStyle = crossColor;
    gameBoardContext.strokeStyle = crossStroke;
    cross.forEach(crossElem => {
        gameBoardContext.fillRect(crossElem.x * tileWidth, crossElem.y * tileHeight, tileWidth, tileHeight);
        gameBoardContext.strokeRect(crossElem.x * tileWidth, crossElem.y * tileHeight, tileWidth, tileHeight);

    })

}

const renderGameOverText = function () {
    gameBoardContext.fillStyle = crossColor;
    gameBoardContext.strokeStyle = crossStroke;
    gameBoardContext.font = "30px Arial";
    gameBoardContext.fillText("Game Over", 3 * tileWidth, 3 * tileHeight);


}
const renderSnakeUnit = function (snakeUnit, idx) {
    gameBoardContext.fillStyle = snakeColor;
    gameBoardContext.strokeStyle = strokeColor;
    gameBoardContext.fillRect(snakeUnit.x * tileWidth, snakeUnit.y * tileHeight, tileWidth, tileHeight);
    gameBoardContext.strokeRect(snakeUnit.x * tileWidth, snakeUnit.y * tileHeight, tileWidth, tileHeight);
}

const clearScreen = function () {
    gameBoardContext.clearRect(0, 0, gameBoard.width, gameBoard.height);
}

const renderSnake = function () {
    snake.forEach(renderSnakeUnit);
}

const renderScore = function () {
    $("#score").html("Score : " + score);
}

const renderScreen = function () {
    gameBoard = createHiDPICanvas();
    renderSnake();
    generateFood();
    renderFood();
}

const createGame = function () {
    renderScore();
    renderScreen();
}

const keyDownEvents = function (event) {
    const LEFT_KEY = [37, 65];
    const RIGHT_KEY = [39, 68];
    const UP_KEY = [38, 87];
    const DOWN_KEY = [40, 83];

    const SPACE = [32];


    const keyPressed = event.keyCode;
    if (LEFT_KEY.includes(keyPressed) && direction != 1) {
        direction = 0;
    }

    if (UP_KEY.includes(keyPressed) && direction != 3) {
        direction = 2
    }

    if (RIGHT_KEY.includes(keyPressed) && direction != 0) {
        direction = 1;
    }

    if (DOWN_KEY.includes(keyPressed) && direction != 2) {
        direction = 3;
    }

    if (SPACE.includes(keyPressed)) {
        $('#startButton').click();
    }
}

$(document).on('keydown', keyDownEvents)

$(document).ready(() => {
    createGame();
})
$(window).resize(() => {
    createGame();
})

const resetGame = function () {
    snake = [...defaultSnakePos];
    direction = 1;
    isGameOver = false;
    score = 0;
    renderScore();
    renderScreen();
}

$("#startButton").on('click', () => {
    isGameRunning = !isGameRunning;
    if (isGameRunning) {
        changeButtonAppearence();
        resetGame();
        gameRunner();
    } else {
        changeButtonAppearence();
    }

})



