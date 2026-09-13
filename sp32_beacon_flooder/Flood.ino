/*
 * ESP32-S3-Zero 200 FUNNY NETWORKS
 * Noms hilarants + tri en premier
 */

#include <WiFi.h>
#include <esp_wifi.h>

#define TX_POWER    78
#define CHANNEL     1
#define NUM_SSIDS   200

uint16_t seqNum = 0;

// ============== 100 PREMIERS NOMS FUNNY ==============
const char* FUNNY_NAMES[] = {
    // Tout en haut (espace)
    " FBI-HEEELLLLOOOOO",
    " MOMY-CALL-YOU",
    " DADDY-IS-HOME",
    " NSA-WATCHING-U",
    " CIA-SURVEILLANCE",
    " PENTAGON-SECURE",
    " ALIENS-INSIDE",
    " GHOST-PROTOCOL",
    " TESLA-FREE-ENERGY",
    " ELON-MUSK-WIFI",
    
    // Urgent
    " URGENT-UPDATE-NEEDED",
    " VIRUS-DETECTED-LOL",
    " YOU-ARE-HACKED",
    " PHONE-IS-INFECTED",
    " CLICK-HERE-FREE",
    " FREE-MONEY-HERE",
    " BITCOIN-MINER-666",
    " DARKWEB-ACCESS",
    " TOR-EXIT-NODE",
    " SILK-ROAD-2.0",
    
    // Famille
    " MOM-I-M-HERE",
    " DAD-WHERE-R-U",
    " GRANNY-S-NET",
    " UNCLE-SAM-WIFI",
    " BIG-BROTHER-IS-WATCHING",
    " SISTER-S-PHONE",
    " BROTHER-S-LAPTOP",
    " COUSIN-DEVICE",
    " NEIGHBOR-SPY",
    " EX-GIRLFRIEND-PHONE",
    
    // Bouffe
    " FREE-PIZZA-HERE",
    " TACO-BELL-FREE",
    " KFC-SECRET-RECIPE",
    " MCDO-WIFI-FREE",
    " STARBUCKS-GOLD",
    " BURGER-KING-5G",
    " SUBWAY-FRESH",
    " DOMINO-PIZZA-FAST",
    " COFFEE-FREE-WIFI",
    " DONUTS-HERE",
    
    // Tech
    " PRINTER-OUT-OF-INK",
    " SMART-FRIDGE",
    " TOASTER-5G",
    " MICROWAVE-WIFI",
    " WASHING-MACHINE",
    " VACUUM-CLEANER",
    " THERMOSTAT-HACKED",
    " DOORBELL-CAM",
    " SECURITY-CAM-01",
    " SMART-TOILET-666",
    
    // Films/Séries
    " SKYNET-ONLINE",
    " MATRIX-EXIT",
    " TRON-LEGACY",
    " GOTHAM-CITY",
    " HOGWARTS-WIFI",
    " DEATH-STAR-5G",
    " ENTERPRISE-NCC-1701",
    " MILLENIUM-FALCON",
    " BATCAVE-SECRET",
    " AVENGERS-TOWER",
    
    // Jeux
    " MINECRAFT-SERVER",
    " FORTNITE-LOBBY",
    " COD-WARZONE",
    " GTA-6-LEAKED",
    " ZELDA-WIFI",
    " MARIO-KART-8",
    " POKEMON-GO-5G",
    " AMONG-US-SUS",
    " ROBLOX-FREE",
    " STEAM-DECK-PRO",
    
    // Divers drôles
    " NOT-A-VIRUS-TRUST-ME",
    " TOTALLY-LEGIT-WIFI",
    " WHY-ARE-U-HERE",
    " GET-OFF-MY-LAWN",
    " I-KNOW-WHERE-U-LIVE",
    " U-R-CLOSE-ENOUGH",
    " TOO-CLOSE-BACK-OFF",
    " PASSWORD-IS-1234",
    " TRY-TO-HACK-ME",
    " NO-FREE-INTERNET",
    
    // Encore
    " HIDDEN-NETWORK-NOT",
    " INVISIBLE-WIFI-LOL",
    " SUPER-SECRET-5G",
    " TOP-SECRET-CLEARANCE",
    " CLASSIFIED-DATA",
    " CONFIDENTIAL-INFO",
    " RESTRICTED-ACCESS",
    " AUTHORIZED-PERSONNEL",
    " EMPLOYEES-ONLY",
    " MEMBERS-EXCLUSIVE"
};

#define NUM_FUNNY (sizeof(FUNNY_NAMES) / sizeof(FUNNY_NAMES[0]))

void setup() {
    Serial.begin(115200);
    delay(1000);
    
    Serial.println("\n=== 200 FUNNY NETWORKS ===");
    
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    delay(100);
    
    WiFi.mode(WIFI_MODE_STA);
    WiFi.setAutoReconnect(false);
    WiFi.disconnect();
    
    esp_wifi_start();
    esp_wifi_set_promiscuous(true);
    esp_wifi_set_ps(WIFI_PS_NONE);
    esp_wifi_set_channel(CHANNEL, WIFI_SECOND_CHAN_NONE);
    esp_wifi_set_max_tx_power(TX_POWER);
    
    Serial.print(NUM_FUNNY);
    Serial.println(" noms predefinis + 100 generes");
    Serial.println("Pret ! Scan ton WiFi...");
}

// ============== GENERATEUR DROLE ==============
void makeFunnySSID(char* buf, int index) {
    const char* prefixes[] = {
        " FBI", " CIA", " NSA", " MOM", " DAD",
        " CAT", " DOG", " UFO", " LOL", " WTF",
        " WOW", " OMG", " BBQ", " KFC", " TNT",
        " VIP", " CEO", " GOD", " DEV", " HAX"
    };
    const char* middles[] = {
        "-LOVES-", "-HATES-", "-FOUND-", "-LOST-",
        "-EATS-", "-SELLS-", "-BUY-", "-STEAL-",
        "-IS-", "-WAS-", "-HAS-", "-NEEDS-"
    };
    const char* suffixes[] = {
        "YOU", "WIFI", "PIZZA", "MONEY", "DATA",
        "PHONE", "SOUL", "CATS", "DOGS", "ALIENS",
        "666", "777", "999", "123", "XXX"
    };
    
    int p = index % 20;
    int m = (index * 3) % 12;
    int s = (index * 7) % 15;
    
    // Commence par espace pour trier en haut
    sprintf(buf, "%s%s%s", prefixes[p], middles[m], suffixes[s]);
}

void sendBeacon(const char* ssid) {
    int ssidLen = strlen(ssid);
    uint8_t frame[256];
    int pos = 0;
    
    // BSSID unique
    uint8_t bssid[6];
    uint32_t hash = 0;
    for (int i = 0; i < ssidLen; i++) hash = hash * 31 + ssid[i];
    bssid[0] = 0x02;
    bssid[1] = (hash >> 16) & 0xFF;
    bssid[2] = (hash >> 8) & 0xFF;
    bssid[3] = hash & 0xFF;
    bssid[4] = (hash >> 24) & 0xFF;
    bssid[5] = (hash >> 4) & 0xFF;
    
    // Header
    frame[pos++] = 0x80; frame[pos++] = 0x00;
    frame[pos++] = 0x00; frame[pos++] = 0x00;
    memset(&frame[pos], 0xFF, 6); pos += 6;
    memcpy(&frame[pos], bssid, 6); pos += 6;
    memcpy(&frame[pos], bssid, 6); pos += 6;
    frame[pos++] = seqNum & 0xFF;
    frame[pos++] = (seqNum >> 8) & 0xFF;
    seqNum++;
    
    // Fixed
    uint64_t ts = esp_timer_get_time();
    for (int i = 0; i < 8; i++) frame[pos++] = (ts >> (i * 8)) & 0xFF;
    frame[pos++] = 0x64; frame[pos++] = 0x00;
    frame[pos++] = 0x11; frame[pos++] = 0x04;
    
    // SSID
    frame[pos++] = 0x00;
    frame[pos++] = ssidLen;
    memcpy(&frame[pos], ssid, ssidLen);
    pos += ssidLen;
    
    // Rates
    frame[pos++] = 0x01; frame[pos++] = 0x08;
    frame[pos++] = 0x82; frame[pos++] = 0x84;
    frame[pos++] = 0x8B; frame[pos++] = 0x96;
    frame[pos++] = 0x24; frame[pos++] = 0x30;
    frame[pos++] = 0x48; frame[pos++] = 0x6C;
    
    // Channel
    frame[pos++] = 0x03; frame[pos++] = 0x01;
    frame[pos++] = CHANNEL;
    
    // RSN WPA2
    frame[pos++] = 0x30; frame[pos++] = 0x14;
    frame[pos++] = 0x01; frame[pos++] = 0x00;
    frame[pos++] = 0x00; frame[pos++] = 0x0F; frame[pos++] = 0xAC; frame[pos++] = 0x04;
    frame[pos++] = 0x01; frame[pos++] = 0x00;
    frame[pos++] = 0x00; frame[pos++] = 0x0F; frame[pos++] = 0xAC; frame[pos++] = 0x04;
    frame[pos++] = 0x01; frame[pos++] = 0x00;
    frame[pos++] = 0x00; frame[pos++] = 0x0F; frame[pos++] = 0xAC; frame[pos++] = 0x02;
    frame[pos++] = 0x00; frame[pos++] = 0x00;
    
    esp_wifi_80211_tx(WIFI_IF_STA, frame, pos, false);
}

void loop() {
    char ssid[64];
    
    // Envoie les 100 noms predefinis
    for (int i = 0; i < NUM_FUNNY && i < 100; i++) {
        // Ajoute espace devant pour trier en haut
        sprintf(ssid, "%s", FUNNY_NAMES[i]);
        sendBeacon(ssid);
        delayMicroseconds(5000);
    }
    
    // Envoie 100 noms generes
    for (int i = 0; i < 100; i++) {
        makeFunnySSID(ssid, i);
        sendBeacon(ssid);
        delayMicroseconds(5000);
    }
    
    delay(1);
    
    static unsigned long last = 0;
    if (millis() - last > 10000) {
        last = millis();
        Serial.println("200 reseaux droles envoyes !");
    }
}