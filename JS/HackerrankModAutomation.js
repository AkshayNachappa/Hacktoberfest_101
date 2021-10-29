// node automation.js --url=https://www.hackerrank.com --config=config.json
// npm init -y
// npm install minimist
// npm install puppeteer -g

/*
config.json format 
{
  "userid": "youruserid",
  "password": "yourpass",
  "moderators": ["abc","efg"]
}

*/

let minimist = require("minimist");
let puppeteer = require("puppeteer");
let fs = require("fs");

let args = minimist(process.argv);

let configJSON = fs.readFileSync(args.config, "utf-8");
let configJSO = JSON.parse(configJSON);

let userid = configJSO.userid;
let password = configJSO.password;
let moderator = configJSO.moderator;

async function run(){
    let browser = await puppeteer.launch({
        headless: false,
        defaultViewport: null,
        args: ['--start-maximized']
    });
    let pages = await browser.pages();
    let page = pages[0];
    await page.goto(args.url);
    
    await page.waitForSelector("a[href='https://www.hackerrank.com/access-account/']");
    await page.click("a[href='https://www.hackerrank.com/access-account/']");

    await page.waitForSelector(`a[href="https://www.hackerrank.com/login"]`);
    await page.click(`a[href="https://www.hackerrank.com/login"]`);

    // await page.waitForNavigation({ waitUntil: 'networkidle2' });

    await page.waitForSelector(`input[name="username"]`);
    await page.click(`input[name="username"]`);
    await page.keyboard.type(userid, {
        delay:30
    });
    
    await page.waitForSelector(`input[name="password"]`);
    await page.click(`input[name="password"]`);
    await page.keyboard.type(password, {
        delay: 30
    });

    await page.waitForSelector(`button[data-analytics="LoginPassword"]`);
    
    await page.click(`button[data-analytics="LoginPassword"]`);    
    
    await page.waitForSelector(`a[href="/contests"]`)
    await page.click(`a[href="/contests"]`)

    await page.waitForSelector(`a[href="/administration/contests/"]`);
    await page.click(`a[href="/administration/contests/"]`);

    await page.waitForSelector(`a[data-attr1="Last"]`);
    // console.log("done");
    let numPages = await page.$eval(`a[data-attr1="Last"]`, function (atag) {
        let totPages = parseInt(atag.getAttribute("data-page"));
        return totPages;
    });
    console.log(numPages);
    
    for(let i = 1; i<=numPages; i++){
        await handleAllPagesOfContest(page,browser);
        if(i!= numPages){
            await page.waitForSelector("a[data-attr1='Right']");
            await page.click("a[data-attr1='Right']");
        }
        
    }

    async function handleAllPagesOfContest(page, browser){
        await page.waitForSelector("a.backbone.block-center");
        let curls = await page.$$eval("a.backbone.block-center",function(atags){
            let urls = [];
            for(let i = 0; i<atags.length; i++){
                let url = atags[i].getAttribute("href");
                urls.push(url);
            }
            return urls;
        });
        console.log(curls);
        await page.waitFor(1000);
        for(let i = 0; i<curls.length; i++){
            let newTab = await browser.newPage();
            await saveModInContest(newTab, args.url+curls[i], configJSO.moderator);
            await newTab.close();
            await page.waitFor(1000);
        }

        

    }
    // function to add all the moderators available
    async function saveModInContest(newTab, curl, mod){
        await newTab.goto(curl);
        await newTab.waitFor(3000);
        await newTab.waitForSelector(`li[data-tab="moderators"]`);
        await newTab.click(`li[data-tab="moderators"]`);
        for(let i = 0; i<mod.length; i++){
        await newTab.waitForSelector(`input#moderator`);
        await newTab.click(`input#moderator`);
        await newTab.keyboard.type(mod[i],{
            delay:30
        });
        await newTab.waitFor(1100);
        await newTab.click(`button.moderator-save`);
        await newTab.waitFor(500);
        }
    }

        await browser.close();
  }
  run();
