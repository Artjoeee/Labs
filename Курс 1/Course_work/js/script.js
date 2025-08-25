let searchForm = document.querySelector('.search-form');

document.querySelector('#search-btn').onclick = () => {
    searchForm.classList.toggle('active');
    shoppingCart.classList.remove('active');
    loginForm.classList.remove('active');
    navbar.classList.remove('active');
}

let shoppingCart = document.querySelector('.shopping-cart');

document.querySelector('#cart-btn').onclick = () => {
    shoppingCart.classList.toggle('active');
    searchForm.classList.remove('active');
    loginForm.classList.remove('active');
    navbar.classList.remove('active');
}

let loginForm = document.querySelector('.login-form');

document.querySelector('#login-btn').onclick = () => {
    loginForm.classList.toggle('active');
    searchForm.classList.remove('active');
    shoppingCart.classList.remove('active');
    navbar.classList.remove('active');
}

let navbar = document.querySelector('.navbar');

document.querySelector('#menu-btn').onclick = () => {
    navbar.classList.toggle('active');
    searchForm.classList.remove('active');
    shoppingCart.classList.remove('active');
    loginForm.classList.remove('active');
}

window.onscroll = () => {
    searchForm.classList.remove('active');
    shoppingCart.classList.remove('active');
    loginForm.classList.remove('active');
    navbar.classList.remove('active');
}
  
function saveAndRedirect() {
    // Получаем данные из формы
    var email = document.getElementById("email").value;

    // Проверяем, содержит ли введенный адрес электронной почты знак '@'
    if (email.includes('@')) {
        // Создаем XML документ
        var xmlData = '<?xml version="1.0" encoding="UTF-8"?>';
        xmlData += '<user>';
        xmlData += '<email>' + email + '</email>';
        xmlData += '</user>';

        // Сохраняем XML данные в localStorage
        localStorage.setItem('userData', xmlData);

        // Переходим на другую страницу
        window.location.href = "savedEmail.html";
    } else {
        // Адрес электронной почты недействителен, выводим сообщение об ошибке
        alert('Пожалуйста, введите действительный адрес электронной почты');
    }
}



var xmlFilePath = 'one.xml';

var xmlhttp = new XMLHttpRequest();
xmlhttp.open("GET", xmlFilePath, true);
xmlhttp.onreadystatechange = function() {
    if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        var xmlDoc = xmlhttp.responseXML;
        var xmlElement = xmlDoc.getElementsByTagName("one")[0];
        var divElement = document.getElementById("one");
        divElement.innerHTML = xmlElement.textContent;
    }
};
xmlhttp.send();



// Массив для хранения товаров в корзине
var cart = [];

// Функция для сохранения корзины в локальное хранилище
function saveCartToLocalStorage() {
    // Преобразуем массив корзины в XML
    var cartXML = '<?xml version="1.0" encoding="UTF-8"?><cart>';

    cart.forEach(function(item) {
        cartXML += '<item>';
        cartXML += '<name>' + item.name + '</name>';
        cartXML += '<price>' + item.price + '</price>';
        cartXML += '<imageSrc>' + item.imageSrc + '</imageSrc>';
        cartXML += '<quantity>' + item.quantity + '</quantity>';
        cartXML += '</item>';
    });

    cartXML += '</cart>';

    // Сохраняем XML-данные корзины в локальное хранилище
    localStorage.setItem('cart', cartXML);
}

// Функция для загрузки корзины из локального хранилища
function loadCartFromLocalStorage() {
    // Получаем XML-данные корзины из локального хранилища
    var cartXML = localStorage.getItem('cart');

    // Если данные есть, парсим их и обновляем корзину
    if (cartXML) {
        var parser = new DOMParser();
        var xmlDoc = parser.parseFromString(cartXML, 'text/xml');
        var items = xmlDoc.getElementsByTagName('item');

        cart = [];

        for (var i = 0; i < items.length; i++) {
            var name = items[i].getElementsByTagName('name')[0].textContent;
            var price = parseFloat(items[i].getElementsByTagName('price')[0].textContent);
            var imageSrc = items[i].getElementsByTagName('imageSrc')[0].textContent;
            var quantity = parseInt(items[i].getElementsByTagName('quantity')[0].textContent);

            addToCart(name, price, imageSrc, quantity);
        }

        // Обновляем отображение корзины
        displayCart();
    }
}

// Вызываем функцию загрузки корзины при загрузке страницы
window.addEventListener('load', loadCartFromLocalStorage);

// Функция для добавления товара в корзину
function addToCart(name, price, imageSrc, quantity = 1) {
    // Создаем объект товара
    var item = {
        name: name,
        price: price,
        imageSrc: imageSrc,
        quantity: quantity
    };

    // Проверяем, есть ли уже такой товар в корзине
    var existingItem = cart.find(function(item) {
        return item.name === name;
    });

    // Если товар уже есть в корзине, увеличиваем его количество
    if (existingItem) {
        existingItem.quantity += quantity;
    } else {
        // Добавляем товар в массив корзины
        cart.push(item);
    }

    // Сохраняем корзину в локальное хранилище
    saveCartToLocalStorage();

    // Обновляем отображение корзины
    displayCart();
}

// Функция для удаления товара из корзины
function removeFromCart(index) {
    // Удаляем товар из массива корзины по индексу
    cart.splice(index, 1);

    // Сохраняем корзину в локальное хранилище
    saveCartToLocalStorage();

    // Обновляем отображение корзины
    displayCart();
}

// Функция для увеличения количества товара в корзине
function increaseQuantity(index) {
    // Увеличиваем количество товара по индексу
    cart[index].quantity++;

    // Сохраняем корзину в локальное хранилище
    saveCartToLocalStorage();

    // Обновляем отображение корзины
    displayCart();
}

// Функция для уменьшения количества товара в корзине
function decreaseQuantity(index) {
    // Уменьшаем количество товара по индексу
    if (cart[index].quantity > 1) {
        cart[index].quantity--;
    } else {
        removeFromCart(index); // Если количество равно 1, удаляем товар из корзины
    }

    // Сохраняем корзину в локальное хранилище
    saveCartToLocalStorage();

    // Обновляем отображение корзины
    displayCart();
}

// Функция для сброса корзины к исходному состоянию
function resetCart() {
    var cartContainer = document.querySelector('.shopping-cart');
    cartContainer.innerHTML = '<div class="total">Корзина пуста</div>';

    // Очищаем корзину в локальном хранилище
    localStorage.removeItem('cart');
}

// Функция для отображения товаров в корзине
function displayCart() {
    // Находим контейнер корзины
    var cartContainer = document.querySelector('.shopping-cart');

    // Очищаем содержимое контейнера
    cartContainer.innerHTML = '';

    // Переменная для хранения итоговой суммы
    var total = 0;

    // Перебираем все товары в корзине
    cart.forEach(function(item, index) {
        // Создаем HTML-элемент для товара
        var itemElement = document.createElement('div');
        itemElement.classList.add('box');

        // Добавляем изображение товара
        var imageElement = document.createElement('img');
        imageElement.src = item.imageSrc;
        itemElement.appendChild(imageElement);

        // Добавляем название товара
        var nameElement = document.createElement('h3');
        nameElement.textContent = item.name;
        itemElement.appendChild(nameElement);

        // Добавляем цену товара
        var priceElement = document.createElement('span');
        priceElement.classList.add('price');
        priceElement.textContent = '$' + item.price.toFixed(2);
        priceElement.style.fontSize = '1.2em'; // Устанавливаем немного меньший размер шрифта для цены
        itemElement.appendChild(priceElement);

        // Добавляем количество товара
        var quantityElement = document.createElement('span');
        quantityElement.textContent = ' ' + item.quantity;
        quantityElement.style.fontSize = '1em'; // Устанавливаем немного меньший размер шрифта для количества
        itemElement.appendChild(quantityElement);

        // Добавляем кнопку увеличения количества товара
        var increaseButton = document.createElement('i');
        increaseButton.classList.add('fas', 'fa-plus');
        increaseButton.addEventListener('click', function() {
            increaseQuantity(index);
        });
        itemElement.appendChild(increaseButton);

        // Добавляем кнопку уменьшения количества товара
        var decreaseButton = document.createElement('i');
        decreaseButton.classList.add('fas', 'fa-minus');
        decreaseButton.addEventListener('click', function() {
            decreaseQuantity(index);
        });
        itemElement.appendChild(decreaseButton);

        // Добавляем элемент удаления товара
        var deleteIcon = document.createElement('i');
        deleteIcon.classList.add('fas', 'fa-trash');
        deleteIcon.addEventListener('click', function() {
            removeFromCart(index);
        });
        itemElement.appendChild(deleteIcon);

        // Добавляем элемент товара в корзину
        cartContainer.appendChild(itemElement);

        // Обновляем итоговую сумму
        total += item.price * item.quantity;
    });

    // Если корзина пуста, отображаем сообщение об этом
    if (cart.length === 0) {
        resetCart();
        return;
    }

    // Создаем HTML-элемент для итоговой суммы
    var totalElement = document.createElement('div');
    totalElement.textContent = 'Итого: ';
    totalElement.style.fontSize = '1.5em'; // Устанавливаем больший размер шрифта для итоговой суммы

    var totalPriceElement = document.createElement('span');
    totalPriceElement.textContent = '$' + total.toFixed(2);
    totalPriceElement.style.fontWeight = 'bold'; // Делаем цену более выделенной
    totalElement.appendChild(totalPriceElement);

    cartContainer.appendChild(totalElement);

    // Создаем кнопку оплаты
    var payButton = document.createElement('button');
    payButton.textContent = 'Оплатить';
    payButton.classList.add('btn');
    payButton.addEventListener('click', function() {
        alert('Для оплаты авторизируйтесь на сайте');
    });
    cartContainer.appendChild(payButton);
}

// Функция для обработки нажатия кнопки "Добавить в корзину"
function handleAddToCartClick() {
    // Получаем информацию о товаре
    var name = "Футбольный мяч";
    var price = 4.99; // Вам нужно определить цену товара
    var imageSrc = "images/ball.png"; // Путь к изображению товара

    // Добавляем товар в корзину
    addToCart(name, price, imageSrc);
}


function login() {
    var email = document.getElementById("entry").value;
    var password = document.getElementById("password").value;

    if (email && password) {
        alert("Данного аккаунта не существует");
    } else {
        alert("Пожалуйста, заполните все поля");
    }
}