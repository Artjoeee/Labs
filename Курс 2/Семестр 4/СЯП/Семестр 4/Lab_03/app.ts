// 1
abstract class BaseUser {
    abstract role: string;
    abstract permissions: string[];
    abstract id: number;
    abstract name: string;

    getRole(): string {
        return this.role;
    }

    getPermissions(): string[] {
        return this.permissions;
    }
}

class Guest extends BaseUser {
    role: string = "Гость";
    permissions: string[] = ["Просмотр контента"];

    constructor(public id: number, public name: string) {
        super();
    }
}

class User extends BaseUser {
    role: string = "Пользователь";
    permissions: string[] = ["Просмотр контента", "Добавление комментариев"];

    constructor(public id: number, public name: string) {
        super();
    }
}

class Admin extends BaseUser {
    role: string = "Пользователь";
    permissions: string[] = [
        "Просмотр контента", "Добавление комментариев",
        "Удаление комментариев", "Управление пользователями"
    ];

    constructor(public id: number, public name: string) {
        super();
    }
}

const guest = new Guest(1, "Аноним");
console.log(guest.getPermissions());

const admin = new Admin(2, "Мария");
console.log(admin.getPermissions());


// 2
interface IReport {
    title: string;
    content: string;
    generate(): string;
}

class HTMLReport implements IReport {
    title: string;
    content: string;

    constructor(reportTitle: string, reportContent: string) {
        this.title = reportTitle;
        this.content = reportContent;
    }

    generate(): string {
        return `<h1>${this.title}</h1><p>${this.content}</p>`;
    }
}

class JSONReport implements IReport {
    title: string;
    content: string;

    constructor(reportTitle: string, reportContent: string) {
        this.title = reportTitle;
        this.content = reportContent;
    }

    generate(): string {
        return JSON.stringify(this);
    }
}

const report1 = new HTMLReport("Отчёт1", "Содержание отчета");
console.log(report1.generate());

const report2 = new JSONReport("Отчёт2", "Содержание отчета");
console.log(report2.generate());


// 3
interface IElement<T> {
    value: T;
    ttl: number;
}

class CacheGeneric<T> {
    start: number;
    map: Map<any, any>;

    constructor() {
        this.start = new Date().getTime();
        this.map = new Map();
    }

    add(key: string, value: T, ttl: number): void {
        this.map.set(key, {value, ttl});
    }

    get(key: string): T | null {
        let end: number = new Date().getTime();
        let time: number = end - this.start;
        let element: IElement<T> = this.map.get(key);

        if (time <= element.ttl) {
            return element.value;
        }
        else {
            return null;
        }   
    }

    clearExpired(): void {
        for (let key of this.map.keys()) {
            if (this.get(key) == null) {
                this.map.delete(key);
            }
        }
    }    
}

const cache = new CacheGeneric<number>();
cache.add("price", 100, 5000)
console.log(cache.get("price"));
setTimeout(() => console.log(cache.get("price")), 6000);


// 4
function createInstance<T>(cls: new (...args: any[]) => T, ...args: any[]): T {
    let object: T = new cls(...args);
    return object;
}

class Product {
    constructor(public name: string, public price: number) {}
}

const p = createInstance(Product, "Телефон", 50000);
console.log(p);


// 5
enum LogLevel {
    INFO = "INFO",
    WARNING = "WARNING",
    ERROR = "ERROR"
};

type LogEntry = [timestamp: Date, level: LogLevel, message: string];

function logEvent(event: LogEntry): void {
    console.log(`[${event[0].toISOString()}] [${event[1]}]: ${event[2]}`);
}

logEvent([new Date(), LogLevel.INFO, "Система запущена"]);


// 6
enum HttpStatus {
    OK = 200,
    NOT_FOUND = 404,
    BAD_REQUEST = 400,
    INTERNAL_SERVER_ERROR = 500
};

type ApiResponse<T> = [status: HttpStatus, data: T | null, error?: string];

function success<T>(data: T): ApiResponse<T> {
    return [HttpStatus.OK, data];
}

function error(message: string, status: HttpStatus): ApiResponse<null> {
    return [status, null, message];
}

const res1 = success({user: "Андрей"});
console.log(res1);

const res2 = error("Не найдено", HttpStatus.NOT_FOUND);
console.log(res2);
