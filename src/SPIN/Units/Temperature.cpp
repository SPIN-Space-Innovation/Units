/**
 * MIT License
 * 
 * Copyright (c) 2023 SPIN - Space Innovation
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "SPIN/Units/Temperature.hpp"

#include <cmath>
#include <optional>
#include <string>

using namespace SPIN::Units;

static const double MinTemperature = 0;
static const double MaxTemperature = 142.0 * std::pow(10.0, 32);

Temperature::Temperature(double value)
{
    this->_temperatureKelvin = value;
}

std::optional<Temperature> Temperature::TryFrom(double temperatureKelvin)
{
    auto temperatureIsLowerThanMin = temperatureKelvin < MinTemperature;
    auto temperatureIsHigherThanMax = MaxTemperature < temperatureKelvin;
    auto temperatureIsNan = std::isnan(temperatureKelvin);

    auto temperatureIsInvalid = temperatureIsLowerThanMin ||
        temperatureIsHigherThanMax ||
        temperatureIsNan;

    if (temperatureIsInvalid)
    {
        return {};
    }

    auto temperatureValue = Temperature(temperatureKelvin);

    return temperatureValue;
}

double Temperature::GetKelvin() const
{
    auto kelvin = this->_temperatureKelvin;
    return kelvin;
}

double Temperature::GetCelcius() const
{
    auto kelvin = this->GetKelvin();
    auto celcius = kelvin - 273.15;
    return celcius;
}

double Temperature::GetFahrenheit() const
{
    auto celcius = this->GetCelcius();
    auto fahrenheit = celcius * 9 / 5 + 32;
    return fahrenheit;
}

Temperature::operator double() const
{
    auto kelvin = this->GetKelvin();

    return kelvin;
}

Temperature::operator float() const
{
    auto kelvinDouble = this->GetKelvin();
    auto kelvinFloat = static_cast<float>(kelvinDouble);

    return kelvinFloat;
}

std::ostream& Temperature::operator<<(std::ostream& os)
{
    auto kelvin = this->GetKelvin();
    
    auto stringRepresentation = std::to_string(kelvin);

    os << stringRepresentation;
    
    return os;
}
